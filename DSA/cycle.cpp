import numpy as np
from sklearn.svm import SVC
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score
from deap import base, creator, tools, algorithms
import multiprocessing

# Constants
NPARTITIONS = multiprocessing.cpu_count()
POPULATION_SIZE = 50
NGEN = 10
CXPB = 0.5
MUTPB = 0.2

# Initialize the random seed
np.random.seed(42)

# Create a dataset
def create_dataset():
    X = np.random.randn(500, 1000)
    y = np.random.randint(5, size=500)
    return train_test_split(X, y, test_size=0.3, random_state=42)

# Create the fitness function
def evaluate(individual, X_train, X_test, y_train, y_test):
    X_train_selected = X_train[:, [i for i, bit in enumerate(individual) if bit]]
    X_test_selected = X_test[:, [i for i, bit in enumerate(individual) if bit]]
    model = SVC(kernel='linear', C=1, decision_function_shape='ovo')
    model.fit(X_train_selected, y_train)
    return (accuracy_score(y_test, model.predict(X_test_selected)),)

# Create the genetic algorithm toolbox
def create_toolbox(X_train, X_test, y_train, y_test):
    creator.create("FitnessMax", base.Fitness, weights=(1.0,))
    creator.create("Individual", list, fitness=creator.FitnessMax)
    toolbox = base.Toolbox()
    toolbox.register("attr_bool", np.random.randint, 2)
    toolbox.register("individual", tools.initRepeat, creator.Individual, toolbox.attr_bool, n=X_train.shape[1])
    toolbox.register("population", tools.initRepeat, list, toolbox.individual)
    toolbox.register("mate", tools.cxTwoPoint)
    toolbox.register("mutate", tools.mutFlipBit, indpb=0.1)
    toolbox.register("select", tools.selTournament, tournsize=3)
    toolbox.register("evaluate", evaluate, X_train=X_train, X_test=X_test, y_train=y_train, y_test=y_test)
    return toolbox

# Run the genetic algorithm
def run_ga(toolbox):
    population = toolbox.population(n=POPULATION_SIZE)
    stats = tools.Statistics(lambda ind: ind.fitness.values)
    stats.register("min", np.min)
    stats.register("max", np.max)
    stats.register("avg", np.mean)
    stats.register("std", np.std)
    hof = tools.HallOfFame(1)
    with multiprocessing.Pool(processes=NPARTITIONS) as pool:
        toolbox.register("map", pool.map)
        population, logbook = algorithms.eaSimple(population, toolbox, cxpb=CXPB, mutpb=MUTPB, ngen=NGEN, stats=stats, halloffame=hof, verbose=True)
    return hof[0]

# Main function
def main():
    X_train, X_test, y_train, y_test = create_dataset()
    toolbox = create_toolbox(X_train, X_test, y_train, y_test)
    best_individual = run_ga(toolbox)
    print("Best individual:", best_individual)
    print("Fitness:", evaluate(best_individual, X_train, X_test, y_train, y_test))

if __name__ == "__main__":
    main()