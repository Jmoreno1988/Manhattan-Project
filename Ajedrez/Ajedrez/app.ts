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
        this.canvas.addEventListener("mousemove", this.changeColor, false);
    }

    getPosition() {
        var x = event.x;
        var y = event.y;
        var canvas = document.getElementById("canvas");

        x -= canvas.offsetLeft;
        y -= canvas.offsetTop;
        var socket = io();
        socket.emit('update position', "X: " + x + ", Y: " + y);
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

class Game {

    private socket: any;

    constructor() {
        this.socket = io();
        //this.socket.emit('newUser', 'pepe');
    }
}

// Esta parte es temporal hasta que tengamos la clase game que gestione todo esto
var isInit = false;

function gameLoop() {
    setTimeout(gameLoop, 100);
    if (!isInit) {
        var board = new Board("canvas", 50, 50);
        board.generateTiles();
    }
    board.draw();


}

window.onload = () => {
    gameLoop();
};