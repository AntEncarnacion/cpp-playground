#include <iostream>
#include <string>
#include <vector>


bool winCondition(const std::vector<std::vector<std::string>>& board, char condition, char color)
{
    bool val = false;
    if (condition == '|')
    {
        for (int i = 0; i < 7; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (color == board[i][j][2] && color == board[i][j + 1][2] && color == board[i][j + 2][2] && color == board[i][j + 3][2])
                {
                    val = true;
                }  // end of if
            }  //  end of for j
        }   //  end of for i
    }  //  end of if |

    else if (condition == '-')
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (color == board[i][j][2] && color == board[i + 1][j][2] && color == board[i + 2][j][2] && color == board[i + 3][j][2])
                {
                    val = true;
                }  // end of if
            }  //  end of for j
        }   //  end of for i
    }  //  end of if -

    else if (condition == '/')
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (color == board[i][j][2] && color == board[i + 1][j + 1][2] && color == board[i + 2][j + 2][2] && color == board[i + 3][j + 3][2])
                {
                    val = true;
                }  // end of if
            }  //  end of for j
        }   //  end of for i
    }  //  end of if 

    else if (condition == '\\')
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 3; j < 6; j++)
            {
                if (color == board[i][j][2] && color == board[i + 1][j - 1][2] && color == board[i + 2][j - 2][2] && color == board[i + 3][j - 3][2])
                {
                    val = true;
                }  // end of if
            }  //  end of for j
        }   //  end of for i
    }  //  end of if 

    return val;

}


std::string who_is_winner(std::vector<std::string> pieces_position_list)
{
    std::vector<std::vector<std::string>> board(7, std::vector<std::string>(6, "empty"));
    enum { A = 0, B, C, D, E, F, G };
    int countA = 0, countB = 0, countC = 0, countD = 0, countE = 0, countF = 0, countG = 0;

    for (int i = 0; i < int(pieces_position_list.size()); i++)
    {
        switch (pieces_position_list[i][0])
        {
        case 'A':
            board[A][countA] = pieces_position_list[i];
            countA++;
            break;
        case 'B':
            board[B][countB] = pieces_position_list[i];
            countB++;
            break;
        case 'C':
            board[C][countC] = pieces_position_list[i];
            countC++;
            break;
        case 'D':
            board[D][countD] = pieces_position_list[i];
            countD++;
            break;
        case 'E':
            board[E][countE] = pieces_position_list[i];
            countE++;
            break;
        case 'F':
            board[F][countF] = pieces_position_list[i];
            countF++;
            break;
        case 'G':
            board[G][countG] = pieces_position_list[i];
            countG++;
            break;
        }  //  end of switch  

        if (winCondition(board, '/', 'Y') || winCondition(board, '\\', 'Y') || winCondition(board, '|', 'Y') || winCondition(board, '-', 'Y'))
        {
            return "Yellow";
        }
        else if (winCondition(board, '/', 'R') || winCondition(board, '\\', 'R') || winCondition(board, '|', 'R') || winCondition(board, '-', 'R'))
        {
            return "Red";
        }
    }  //  end of for loop

    return "Draw";

}  //  end of who is winner function


int main()
{
    std::vector<std::string> pieces_position_list
    {
               "A_Yellow",
                "B_Red",
                "B_Yellow",
                "C_Red",
                "G_Yellow",
                "C_Red",
                "C_Yellow",
                "D_Red",
                "G_Yellow",
                "D_Red",
                "G_Yellow",
                "D_Red",
                "F_Yellow",
                "E_Red",
                "D_Yellow"
    };
    std::cout << who_is_winner(pieces_position_list) << std::endl;

	return 0;
}