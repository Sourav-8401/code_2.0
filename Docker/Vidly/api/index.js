const express = require('express')
const cors = require('cors')
const PORT = 3001
const app = express();
app.use(cors())
app.get('/', (req, res)=>{
    res.send(
        "<h2> Welcome To server</h2>"
    )
})
app.get('/user', (req,res)=>{
    res.status(200).json({
        "user1" : {
            "username" : "honey1",
            "age" : 24
        },
        "user2" : {
            "username" : "honey2",
            "age" : 21
        },
        "user3" : {
            "username" : "honey3",
            "age" : 22
        },
        "user4" : {
            "username" : "honey4",
            "age" : 29
        }
    })
})
app.listen(PORT, ()=>{
    console.log(`Server is started ON: ${PORT} `);
})