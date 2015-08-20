declare var io;

class Tile {

    private posX: number;
    private posY: number;
    private color: number; // 0 black, 1 white

    constructor(posX: number, posY: number, color: number) {
        this.posX = posX;
        this.posY = posY;
        this.color = color;
    }

    draw(ctx: any) {
        if (this.color == 0)
            ctx.fillStyle = "#000000"; // black
        else
            ctx.fillStyle = "#FFFFFF"; // white
        ctx.fillRect(this.posX, this.posY, 50, 50);
    }
}

class Board {

    private canvas: any;
    private ctx: any;
    private sizeX: number;
    private sizeY: number;
    private tiles: any[][] = [[8], [8], [8], [8], [8], [8], [8], [8]];
    private socket: any;

    constructor(canvas: string, sizeX: number, sizeY: number) {
        this.canvas = document.getElementById(canvas);
        this.ctx = this.canvas.getContext("2d");
        this.sizeX = sizeX;
        this.sizeY = sizeY;

        // Events
        this.socket = io();
        this.socket.on('update position', function (msg) {
            document.getElementById("log").innerHTML = msg;
        });

        this.canvas.addEventListener("mousedown", this.getPosition, false);
        this.canvas.addEventListener("mousemove", this.getPosition, false);
    }

    getPosition() {
        var x = event.x;
        var y = event.y;
        var canvas = document.getElementById("canvas");

        x -= canvas.offsetLeft;
        y -= canvas.offsetTop;
        var socket = io();
        socket.emit('update position', {
            idClient: idClient,
            data: {
                position: [x, y]
            }
        });
    }

    changeColor() {

    }

    generateTiles() {
        var x = 0;
        var y = 0;
        var color = 1;

        for (var i = 0; i < 8; i++) {
            for (var a = 0; a < 8; a++) {
                this.tiles[i][a] = new Tile(x, y, color);
                x += this.sizeY;
                color = (color == 1) ? 0 : 1;
            }
            y += this.sizeY;
            x = 0;
            color = (color == 1) ? 0 : 1;
        }
    }

    draw() {
        for (var i = 0; i < 8; i++) {
            for (var a = 0; a < 8; a++) {
                this.tiles[i][a].draw(this.ctx);
            }
        }
    }
}



class Socket {

    constructor() { }

    private newSocket() { }
    private createHandler() { }
    private sendMessage() { }


}

var idClient = Math.floor(Math.random() * 10000);

class Game {

    private socket: any;
    private isready: boolean;
    private idSocket: number;

    constructor() {
        this.socket = io();
        //this.socket.emit('newUser', 'pepe');
    }

    public connectServer(name: string) {
        var socket = io();
        var that = this;

        socket.on('connect', function (data) {
            socket.emit('send client info', { customId: idClient, name: name });
        });

        this.socket.on('update players', function (msg) {
            var text = "Users connected: <br>";
            for (var i = 0; i < msg.players.length; i++) {
                text += " - " + msg.players[i].name + "<br>"
            }

            document.getElementById("players").innerHTML = text;
        });

        this.socket.on('update position in client', function (msg) {
            var text = "<br>";
            for (var i = 0; i < msg.length; i++) {
                text += "(x: " + msg[i].position[0] + ", y: " + msg[i].position[1] + ")<br>"
            }

            document.getElementById("clicks").innerHTML = text;
        });
        
    }

    public initGame() { }

    public gameLoop() { }
}

window.onload = () => {
    var userName = prompt("Please enter your name", "Harry Potter");
    var game = new Game();
    var board = new Board("canvas", 50, 50);

    board.generateTiles();
    board.draw();

    game.connectServer(userName);
};