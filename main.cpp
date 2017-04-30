#include "core/uct.h"
#include <iostream>

void mainServer(bool first, int ai_seconds)
{
    MatrixXd board;
    reversiInit(board);

    bool turn(first);

    while (!reversiIsTerminal(board))
    {
        if (turn)
        {
            UCTTree uctt(board, first, Position(-1, -1));
            Position best_AI_pos;
            if (uctt.UCTSearch(ai_seconds, best_AI_pos))
            {
                std::printf("AI (%d, %d)\n", best_AI_pos.x(), best_AI_pos.y());
                reversiStepOnPos(board, best_AI_pos, first);
            }
            else
            {
                std::cout << "PASS!" << std::endl;
            }
            turn = !turn;
        }
        else
        {
            int x, y;
            std::cin >> x >> y;
            reversiStepOnPos(board, Position(x, y), !first);
            turn = !turn;
        }
    }
}

int main()
{
//    MatrixXd test(8, 8);
//    test << -1, 0, 0, 0, 0, 0, 0, 0,
//    0 ,-1 , 0, -1  ,0 , 0  ,0 , 0,
//    0 , 0 ,-1, -1  ,0 , 0  ,0  ,0,
//    0  ,0 ,-1, -1  ,1 , 0  ,0  ,0,
//    0  ,0 , 1 ,-1 ,-1  ,1  ,1 , 0,
//    0  ,1 ,0  ,1 ,-1  ,1  ,0 , 1,
//    0  ,0 , 0 , 0,  1 ,-1  ,1 ,-1,
//    0  ,0 , 0  ,0 , 0  ,0 ,-1 ,-1;
    mainServer(true, 3);

//    vector<int> test_pos;
//    reversiNextValidPos(test, true, test_pos);
//    for (int i = 0; i != test_pos.size() / 3; i++)
//    {
//        std::printf("(%d, %d)", test_pos[3 * i], test_pos[3 * i + 1]);
//    }
//    std::cout << '\n';
//
//    std::cout << test;
}
