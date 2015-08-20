var app = require('express')();
var http = require('http').Server(app);
var io = require('socket.io')(http);
var clients = [];

// Routes 
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

    socket.on('send client info', function (data) {
        var clientInfo = {
            customId: data.customId,
            clientId: socket.id,
            name: data.name,
            position: [0, 0]
        }
        clients.push(clientInfo)

        io.emit('update players', { players: clients });
    });

    socket.on('update position', function (msg) {
        var client = searchClient(msg.idClient);
        client.position = msg.data.position;

        io.emit('update position in client', clients);
    });

    socket.on('disconnect', function (data) {
        for (var i = 0, len = clients.length; i < len; ++i) {
            var c = clients[i];

            if (c.clientId == socket.id) {
                clients.splice(i, 1);
                break;
            }
        }

        io.emit('update players', { players: clients });
        io.emit('update position in client', clients);
    });

});

http.listen(3000, function () {
    console.log('listening on *:3000');
});

function searchClient(id) {
    var client = {}
    for (var i = 0; i < clients.length; i++) {
        if (id == clients[i].customId) {
            client = clients[i];
        }
    }
    return client;
}
