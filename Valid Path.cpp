
int matrix[100][100];
int visited[100][100];
int max_X;
int max_Y;

bool valid(int x, int y)
{
    if(x >= 0 && y >= 0 && x <= max_X && y <= max_Y && visited[x][y] == 0 && matrix[x][y] == 0)
    {
        return true;
    }
    return false;
}

bool dist(int x_cor, int y_cor, int circle_center_x_cor, int circle_center_y_cor, int radius)
{
    if((x_cor-circle_center_x_cor)*(x_cor-circle_center_x_cor) + (y_cor-circle_center_y_cor)*(y_cor-circle_center_y_cor) <= radius*radius)
    {
        return true;
    }
    return false;
}


string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F)
{


    //sab ko kar diya zero.....
    memset(matrix, 0, sizeof(matrix));
    memset(visited, 0, sizeof(visited));
    //center vector may sare circle ke center ko rakh diya....

    max_X = A;
    max_Y = B;
    vector<pair<int, int> > center_vector;
    for(int iter = 0; iter < C; iter++)
    {
        center_vector.push_back(make_pair(E[iter], F[iter]));
    }


    for(int iter = 0; iter <= A+1; iter++)
    {
        for(int jter = 0; jter <= B+1; jter++)
        {
            bool flag = true;
            for(int kter = 0; kter < C; kter++)
            {


           //     cout << matrix[iter][jter] <<" " << dist(iter, jter, center_vector[kter].first, center_vector[kter].second, D) << endl;

                if(dist(iter, jter, center_vector[kter].first, center_vector[kter].second, D))
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
            {
                matrix[iter][jter] = 0;
            }
            else
            {
                matrix[iter][jter] = 1;
            }



        }
    }
  /*  for(int iter = 0; iter< 64; iter++)
    {
        for(int jter = 0; jter < 64; jter++)
        {

            cout << matrix[iter][jter] << " ";
        }
        cout << endl;
    }*/


    if(matrix[0][0] == 1 || matrix[A][B] == 1)
    {
        //cout << "yaha hu." <<endl;
        string str = "NO";
        return str;
    }
    else
    {
        visited[0][0] = 1;





    //yaha say bfs wala kam chalu.....
    queue<pair<int, int> > q;
    q.push(make_pair(0, 0));
    int dest1 = A;
    int dest2 = B;

    while(!q.empty())
    {
      //  cout << q.size() << endl;
        pair<int, int> temp = q.front();

        q.pop();
        int x = temp.first;
        int y = temp.second;
      //  cout << x << " " << y << endl;
        if(x == dest1 && y == dest2)
        {
           // cout << "hello" <<endl;
            string ret = "YES";
            return ret;
        }
        if(valid(x-1, y))
        {
            visited[x-1][y] = 1;
            q.push(make_pair(x-1,y));
        }

        if(valid(x-1, y+1))
        {
            visited[x-1][y+1] = 1;
            q.push(make_pair(x-1, y+1));
        }

        if(valid(x, y+1))
        {
            visited[x][y+1] = 1;
            q.push(make_pair(x, y+1));
        }

        if(valid(x+1, y+1))
        {
            visited[x+1][y+1] = 1;
            q.push(make_pair(x+1, y+1));
        }

        if(valid(x+1, y))
        {
            visited[x+1][y] = 1;
            q.push(make_pair(x+1, y));
        }


        if(valid(x+1, y-1))
        {
            visited[x+1][y-1] = 1;
            q.push(make_pair(x+1, y-1));
        }

        if(valid(x, y-1))
        {
            visited[x][y-1] = 1;
            q.push(make_pair(x, y-1));
        }

        if(valid(x-1, y-1))
        {
            visited[x-1][y-1] = 1;
            q.push(make_pair(x-1, y-1));
        }

    }

    string str = "NO";
    return str;
}
}
