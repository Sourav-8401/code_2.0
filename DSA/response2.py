import numpy as np
from sklearn.svm import SVC
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score
from deap import base, creator, tools
import multiprocessing
import time
from tabulate import tabulate


# Create a toolbox with parallel support
def create_toolbox(X_train, X_test, y_train, y_test, num_features):
    creator.create("FitnessMax", base.Fitness, weights=(1.0,))
    creator.create("Individual", list, fitness=creator.FitnessMax)
    toolbox = base.Toolbox()
    toolbox.register("attr_bool", np.random.randint, 2)
    toolbox.register("individual", tools.initRepeat, creator.Individual,
                     toolbox.attr_bool, n=num_features)
    toolbox.register("population", tools.initRepeat, list, toolbox.individual)
    toolbox.register("mate", tools.cxTwoPoint)
    toolbox.register("mutate", tools.mutFlipBit, indpb=0.1)
    toolbox.register("select", tools.selTournament, tournsize=3)
    toolbox.register("evaluate", evaluate_individual, X_train=X_train,
                     X_test=X_test, y_train=y_train, y_test=y_test)
    return toolbox


# Function to evaluate an individual
def evaluate_individual(individual, X_train, X_test, y_train, y_test):
    features = [i for i, bit in enumerate(individual) if bit]
    if not features:
        return (0,)  # if no features are selected, return a fitness of 0
    try:
        X_train_selected = X_train[:, features]
        X_test_selected = X_test[:, features]

        if X_train_selected.shape[1] == 0 or X_test_selected.shape[1] == 0:
            return (
            0,)  # if no features are selected after slicing, return a fitness of 0

        model = SVC(kernel='linear', C=1, decision_function_shape='ovo')
        model.fit(X_train_selected, y_train)
        y_pred = model.predict(X_test_selected)
        accuracy = accuracy_score(y_test, y_pred)
        return (accuracy,)
    except Exception as e:
        print(f"Error evaluating individual: {e}")
        return (0,) # for any other error, return a fitness of 0


# Main function
def main():
    np.random.seed(42)
    X = np.random.randn(500, 1000)
    y = np.random.randint(5, size=500)
    X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3,
                                                        random_state=42)
    num_features = X.shape[1]
    toolbox = create_toolbox(X_train, X_test, y_train, y_test, num_features)
    population = toolbox.population(n=50)
    ngen, cxpb, mutpb = 10, 0.5, 0.2

    # Use multiprocessing for parallel evaluation with a context manager
    with multiprocessing.Pool(processes=multiprocessing.cpu_count()) as pool:
        toolbox.register("map", pool.map)

        for gen in range(ngen):
            offspring = toolbox.select(population, len(population))
            offspring = list(map(toolbox.clone, offspring))
            for child1, child2 in zip(offspring[::2], offspring[1::2]):
                if np.random.rand() < cxpb:
                    toolbox.mate(child1, child2)
                    del child1.fitness.values
                    del child2.fitness.values
            for mutant in offspring:
                if np.random.rand() < mutpb:
                    toolbox.mutate(mutant)
                    del mutant.fitness.values
            invalid_ind = [ind for ind in population + offspring if
                           not ind.fitness.valid]
            fitnesses = toolbox.map(toolbox.evaluate, invalid_ind)
            for ind, fit in zip(invalid_ind, fitnesses):
                ind.fitness.values = fit
            population[:] = toolbox.select(population + offspring, len(population))
            fits = [ind.fitness.values[0] for ind in population if
                    ind.fitness.valid]

            # Print statistics in a tabular form
            stats = [["Min", min(fits)],
                     ["Max", max(fits)],
                     ["Avg", sum(fits) / len(fits)],
                     ["Std", abs(sum(x * x for x in fits) / len(fits) - (sum(fits) / len(fits)) ** 2) ** 0.5]]

            print(f"Generation {gen+1} statistics:")
            print(tabulate(stats, headers=["Statistic", "Value"], tablefmt="grid"))
            print()

    best_individual = tools.selBest(population, 1)[0]
    return best_individual


if __name__ == "__main__":
    start_time = time.time()
    best_individual = main()
    print("Best individual:", best_individual)
    print("Time taken:", time.time() - start_time)