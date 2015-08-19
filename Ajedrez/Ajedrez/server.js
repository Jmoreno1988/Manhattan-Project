var app = require('express')();
var http = require('http').Server(app);
var io = require('socket.io')(http);

app.get('/', function (req, res) {
    res.sendFile(__dirname + '/index.html');
});

app.get('/app.css', function (req, res) {
    res.sendFile(__dirname + '/app.css');
});

app.get('/app.js', function (req, res) {
    res.sendFile(__dirname + '/app.js');
});

io.on('connection', function (socket) {

    console.log('New user connected');

    socket.on('update position', function (msg) {
        io.emit('update position', msg);
        console.log(msg);
    });

    socket.on('disconnect', function () {
        console.log('User disconnected');
    });

});

http.listen(3000, function () {
    console.log('listening on *:3000');
});
