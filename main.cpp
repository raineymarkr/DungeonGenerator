#include <iostream>
#include <vector>

int width;
int height;
int res;


//Basic piece
struct Piece
{
    //each piece should have a string marker
    std::string marker;

    //location on the map
    int pos_x;
    int pos_y;

    //if this piece is passable
    bool passable = false;

    //print the piece
    void printpiece()
    {
        std::cout << marker;
    }

};

//player piece
struct Player:Piece
{
    //set player market on initialize
    Player()
    {marker = "ỻ ";}

};

//Same as player, just more simple for now
struct Monster:Piece
{
    Monster()
    {marker = "M ";
    }
};

//Wall piece
struct Wall:Piece
{
    Wall(){marker = "* ";}

};

//Floor piece is passable
struct Floor:Piece
{
    Floor(){marker = "  ", passable = true;}

};

//define the board
struct Board
{
    int num;

    //define seed start
    int initX = 1;
    int initY = 1;

    //counter variable
    int counter = 0;

    //if visited
    bool visited = false;

    //board array
    Piece arrBoard[100][100];

    //player and monster array
    Piece arrPieces[2];




void GenerateBoard(Wall& wall, Floor& floor)
    {
        for(int col = 0; col <= height; col++)
         {
            for(int row = 0; row <= width; row++)
            {
                arrBoard[col][row] = wall;
            }

            }
        //arrBoard[0][0] = floor;
        }

void checkRndNeighbor(Floor &floor)
{
    int rnd = rand() % 4;

    switch(rnd)
    {
    case 0:
        {
            initY --;

        if(initY < 1)
            {
            initY ++;
            } else

        if( arrBoard[initY][initX].passable == false)
            {
            arrBoard[initY][initX] = floor;
            counter++;
            }
            break;
        }

    case 1:
        {
            initX --;

        if(initX < 1)
            {
            initX ++;
            } else

        if( arrBoard[initY][initX].passable == false)
            {
            arrBoard[initY][initX] = floor;
            counter++;
            }
            break;
        }


    case 2:
        {
            initX ++;

        if(initX > width-1)
            {
            initX --;
            } else

        if( arrBoard[initY][initX].passable == false)
            {
            arrBoard[initY][initX] = floor;
            counter++;
            }
            break;
        }

    case 3:
        {
            initY ++;

        if(initY > height-1)
            {
            initY --;
            } else

        if( arrBoard[initY][initX].passable == false)
            {
            arrBoard[initY][initX] = floor;
            counter++;
            }
            break;
        }
    }
}

void PrintMaze(Piece board[100][100])
{
    for(int col = 0; col <= height; col++)
         {
            for(int row = 0; row <= width; row++)
            {
                board[col][row].printpiece();
            }
            std::cout << std::endl;
         }
}

void GenerateMaze(Piece board[100][100], Floor &floor)
{
    for(int i = 0; i <= res; i++)
            {
                checkRndNeighbor(floor);
            }
}

void SetPos(Player &piece, Monster &monster, Board &board)
    {
        bool flag=true;
        bool flag2=true;
        while(flag == true && flag2 == true)
        {
            piece.pos_x = rand() % height-1;
            piece.pos_y = rand() % width-1;

            monster.pos_x = rand() % height-1;
            monster.pos_y = rand() % width-1;

            if(board.arrBoard[piece.pos_y][piece.pos_x].passable == true && board.arrBoard[monster.pos_y][monster.pos_x].passable == true)
            {
                flag = false;
                flag2 = false;
            } else
                while(flag == true && flag2 == true)
                    {
                        if(board.arrBoard[piece.pos_y][piece.pos_x].passable == false)
                        {
                            piece.pos_x = rand() % height-1;
                            piece.pos_y = rand() % width-1;
                        } else
                            {

                                flag = false;
                            }

                        if(board.arrBoard[monster.pos_y][monster.pos_x].passable == false)
                        {
                            monster.pos_x = rand() % height-1;
                            monster.pos_y = rand() % width-1;
                        } else
                        {
                            flag2 = false;
                        }
                    }
        }
    }


void PlaceCharacter(Piece arrPieces[2])
{
     for(int col = 0; col <= height; col++)
         {
            for(int row = 0; row <= width; row++)
            {
                int i = 0;
                if(arrPieces[i].pos_x == row && arrPieces[i].pos_y == col)
                {
                    arrBoard[col][row] = arrPieces[i];
                } else if(arrPieces[i+1].pos_x == row && arrPieces[i+1].pos_y == col)
                {
                    arrBoard[col][row] = arrPieces[i+1];
                }
            }
         }
}

    //move player
    void move(Player &piece, Monster &monster, Floor &floor, Wall &wall, Board &board)
    {
        //input variable
        char dir;

        //Movement cases
        std::cout << "Move:\nw: North\na: East\ns: South\nd: West\n";
        std::cin >> dir;
        switch(dir)
        {
        case 'w':

            if(arrBoard[piece.pos_y-1][piece.pos_x].passable == true)
            {
                arrBoard[piece.pos_y][piece.pos_x] = floor;
                piece.pos_y = piece.pos_y - 1;
            }
            break;


        case 's':
            if(arrBoard[piece.pos_y+1][piece.pos_x].passable == true)
            {
            arrBoard[piece.pos_y][piece.pos_x] = floor;
            piece.pos_y = piece.pos_y + 1;
            }
            break;


        case 'd':
            if(arrBoard[piece.pos_y][piece.pos_x+1].passable == true)
            {
            arrBoard[piece.pos_y][piece.pos_x] = floor;
            piece.pos_x = piece.pos_x + 1;
            }
            break;

        case 'a':
            if(arrBoard[piece.pos_y][piece.pos_x-1].passable == true)
            {
            arrBoard[piece.pos_y][piece.pos_x] = floor;
            piece.pos_x = piece.pos_x - 1;
            }
            break;

        case 'm':
            std::cout << "Input Width:";
            std::cin >> width;
            std::cout << "Input Height:";
            std::cin >> height;
            std::cout << "Input Resolution: ";
            std::cin >> res;

            GenerateBoard(wall, floor);
            GenerateMaze(arrBoard, floor);
            SetPos(piece, monster, board);
            PlaceCharacter(arrPieces);
            PrintMaze(arrBoard);
            break;
        }


    }

};




int main()
{
    srand(time(0));

    int choice;
    Board board{ width , height };
    Player piece;
    Wall wall;
    Floor floor;
    Monster monster;
    bool flag = true;
    bool gameloop = true;

while(flag == true)
    {
    std::cout << "1. Generate Maze\n2. Navigate Current Maze\n";
    std::cin >> choice;
    if(choice == 1)
        {

            std::cout << "Input Width:";
            std::cin >> width;
            std::cout << "Input Height:";
            std::cin >> height;
            std::cout << "Input Resolution: ";
            std::cin >> res;

            board.GenerateBoard(wall, floor);
            board.GenerateMaze(board.arrBoard, floor);
            board.SetPos(piece, monster, board);
            board.arrPieces[0] = piece;
            board.arrPieces[1] = monster;
            board.PlaceCharacter(board.arrPieces);
            board.PrintMaze(board.arrBoard);
        } else if (choice == 2)
            {flag = false;
            while (gameloop == true)
            {
            board.move(piece, monster, floor, wall, board);
            board.arrPieces[0] = piece;
            board.PlaceCharacter(board.arrPieces);
            board.PrintMaze(board.arrBoard);
            }


    }}


    return 0;
}
