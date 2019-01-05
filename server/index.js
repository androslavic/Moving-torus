function Buffer (value){
  this.value = value;
}

var buffer = new Buffer('');

const fs = require('fs');

const SerialPort = require('serialport')

const port = new SerialPort('COM3'  , {autoOpen:true,baudRate:9600,dataBits: 8,stopBits: 1})

port.open(function (err){
  if (err) {
    return console.log('Error opening port: ', err.message)
  }
})

i=0;
var jsonArr = [];

  port.on('data', function (data) {
      buffer.value+=data

    if (buffer.value.includes(".")){
    console.log('Data:', buffer.value)
    var xValue = buffer.value.substring(buffer.value.indexOf('X') + 1, buffer.value.indexOf('/'));
    var yValue = buffer.value.substring(buffer.value.indexOf('Y') + 1, buffer.value.indexOf(','));
    var zValue = buffer.value.substring(buffer.value.indexOf('Z') + 1, buffer.value.indexOf('.'));
        jsonArr.push({
            x: xValue,
            y: yValue,
            z: zValue
        });
        let data = JSON.stringify(jsonArr);
        fs.writeFileSync('server/data.json', data)

    buffer.value=''
    i=i+1;
    if (i==1000) {

sleep(10);}
      }


    })


    module.exports = {
      output: buffer.value
    }
