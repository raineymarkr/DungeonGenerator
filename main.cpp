#include <iostream>
#include <vector>

struct Piece
{
    std::string marker;
    int pos_x;
    int pos_y;
    //int dir;

    bool passable = false;

    void printpiece()
    {
        std::cout << marker;
    }

};

struct Player:Piece
{
    Player()
    {marker = "ỻ ";}

    void move()
    {
        char dir;
        std::cout << "Move:\nw: North\na: East\ns: South\nd: West\n";
        std::cin >> dir;
        switch(dir)
        {
        case 'w':
            pos_y = pos_y - 1;
            break;


        case 's':
            pos_y = pos_y + 1;
            break;


        case 'd':
            pos_x = pos_x + 1;
            break;

        case 'a':
            pos_x = pos_x - 1;
            break;
        }


    }
};

struct Monster:Piece
{
    Monster()
    {marker = "M ";
    }
};

struct Wall:Piece
{
    Wall(){marker = "* ";}

};

struct Floor:Piece
{
    Floor(){marker = "  ", passable = true;}

};


struct Board
{
    int width = 20;
    int height = 20;
    int num;
    int initX = 0;
    int initY = 0;
    int counter = 0;
    bool visited = false;
    Piece arrBoard[20][20];
    Floor floor;


void GenerateBoard(Wall& wall)
    {
        for(int col = 0; col < width; col++)
         {
            for(int row = 0; row < height; row++)
            {
                arrBoard[col][row] = wall;
                wall.printpiece();

                /**Insert Characters
                int i = 0;
                if(arrPieces[i].pos_x == row && arrPieces[i].pos_y == col)
                {
                    std::cout << arrPieces[i].marker;
                } else if(arrPieces[i+1].pos_x == row && arrPieces[i+1].pos_y == col)
                {
                    std::cout << arrPieces[i+1].marker;
                } else
                {
                        flag = true;
                    }
                    **/
            }
            std::cout << std::endl;

            }
        arrBoard[0][0] = floor;
        }

void checkRndNeighbor()
{
    int rnd = rand() % 4;

    switch(rnd)
    {
    case 0:
        {
            initY --;

        if(initY < 0)
            {
            initY ++;
            } else

        if( arrBoard[initX][initY].passable == false)
            {
            arrBoard[initX][initY] = floor;
            counter++;
            }
            break;
        }

    case 1:
        {
            initX --;

        if(initX < 0)
            {
            initX ++;
            } else

        if( arrBoard[initX][initY].passable == false)
            {
            arrBoard[initX][initY] = floor;
            counter++;
            }
            break;
        }


    case 2:
        {
            initX ++;

        if(initX > 20)
            {
            initX --;
            } else

        if( arrBoard[initX][initY].passable == false)
            {
            arrBoard[initX][initY] = floor;
            counter++;
            }
            break;
        }

    case 3:
        {
            initY ++;

        if(initY > 20)
            {
            initY --;
            } else

        if( arrBoard[initX][initY].passable == false)
            {
            arrBoard[initX][initY] = floor;
            counter++;
            }
            break;
        }
    }
};


void PrintMaze(Piece board[20][20])
{
    for(int col = 0; col <= 19; col++)
         {
            for(int row = 0; row <= 19; row++)
            {
                board[col][row].printpiece();
            }
            std::cout << std::endl;
         }
};

void GenerateMaze(Piece board[20][20])
{
    for(int i = 0; i <= 400; i++)
            {
                checkRndNeighbor();
            }
    std::cout << std::endl << std::endl;
    PrintMaze(board);
        }

};




int main()
{
    srand(time(0));

    Board board{ 20, 20 };
    Player piece;
    Wall wall;
    Floor floor;
    piece.pos_x = 1;
    piece.pos_y = 1;
    Monster monster;
    monster.pos_x = 3;
    monster.pos_y = 3;
    Piece arrPieces[2] = {piece, monster};

    board.GenerateBoard(wall);
    board.GenerateMaze(board.arrBoard);
    /**while (true)
    {
    piece.move();
    arrPieces[0] = piece;
    board.GenerateBoard(wall);
    board.GenerateMaze(board.arrBoard);
    }**/


    return 0;
}
