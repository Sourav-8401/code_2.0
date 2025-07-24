const myArr = [1,2,4,9,62,0,52,2]
const strArr = ['a', 'b', 'c', 'ab', 'acb', 'q']
const obj = [];

o1 = {
    name : "sourav",
    age : 21
}
o5 = {
    name : "sourav",
    age : 13
}

o2 = {
    name : "1sourav",
    age : 2
}

o3 = {
    name : "Asourav",
    age : 29
}

o4 = {
    name : "Nmsourav",
    age : 11
}
obj.push(o1,o2,o3,o4,o5);

obj.sort((a,b)=>{
    if(a.name == b.name){
        return a.age - b.age;
    }
    return b.name.localeCompare(a.name)
})

strArr.sort();
myArr.sort((a,b)=>{
    return b - a;
});
console.log(myArr);

localStorage.clear();
localStorage.setItem("name", "1sourav");
localStorage.setItem("age", "21");
localStorage.setItem("gender", "Male");
console.log(localStorage.getItem("name"));


const strObj = JSON.stringify(obj);
const revStrObj = JSON.parse(strObj);
console.log(strObj);
console.log(revStrObj[0].name)
let arr = ["a", "b"];

arr.push(function() {
  console.log("gentle")
});

arr[2]();