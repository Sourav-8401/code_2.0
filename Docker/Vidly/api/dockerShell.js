const {exec} = require('child_process');

const fillData = async()=>{
    const data =  await new Promise((res,rej)=>{exec('docker imag', (err, sout, serr)=>{
        res(sout);
    });})
    console.log(data);
}
fillData();