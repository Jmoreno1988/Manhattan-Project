var path = require("path");

module.exports = function (app) {

    app.get('/', function (req, res) {
        res.sendFile(path.resolve(__dirname + '/../index.html'));
    });

    app.get('/app.css', function (req, res) {
        res.sendFile(path.resolve(__dirname + '/../app.css'));
    });

    app.get('/app.js', function (req, res) {
        res.sendFile(path.resolve(__dirname + '/../app.js'));
    });

}