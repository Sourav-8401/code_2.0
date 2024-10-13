const express = require("express")
const app = express();
const PORT = process.env.PORT || 3001
app.get("/", (req, res)=>{
    return res.json({
        message : "this is server"
    })
})

app.listen(PORT, ()=>{
    console.log(`app is running on port:${PORT}`)
})