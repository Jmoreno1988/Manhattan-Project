app.get('/', function (req, res) {
    res.sendFile(__dirname + '/index.html');
});

app.get('/app.css', function (req, res) {
    res.sendFile(__dirname + '/app.css');
});

app.get('/app.js', function (req, res) {
    res.sendFile(__dirname + '/app.js');
});