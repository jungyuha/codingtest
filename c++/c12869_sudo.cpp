/*
1. 입력
<1>
3
54 18 6
<2>
1
60

2. 9 3 1 경우의 수
9 3 1 
9 1 3
3 1 9
3 9 1
1 3 9
1 9 3

3. <1> 시나리오 : 최단 거리(BFS)
54 18 6
    9 3 1 
        9 3 1 
        9 1 3
        3 1 9
        3 9 1
        1 3 9
        1 9 3
    9 1 3
        이하 동일
    3 1 9
    3 9 1
    1 3 9
    1 9 3

3. <2> 시나리오 : 최단 거리(BFS)
60
    9 3 1 
        9 3 1 
        9 1 3
        3 1 9
        3 9 1
        1 3 9
        1 9 3
    9 1 3
        이하 동일
    3 1 9
    3 9 1
    1 3 9
    1 9 3

4. 구현
int res=0;
vector<int> dd[6] = {{9,3,1},{9,1,3},{3,1,9},...};
queue <vector<int>> q;

vector<int> ori = {0(level),54,18,6};
q.push(ori);
while(q.size())
//res++;
q [{0,54,18,6}]
vector<int> pop = q.front();
    (순회) dd[6] {{9,3,1}(선),{9,1,3},{3,1,9},...}
        vector<int> new;
        bool yn = true;
        new.push_back(pop[0]+1);
        (순회) pop[1-3] {54(선),18,6}
            if(54(선) - 9(선) > 0) yn = false;
            new.push_back(pop[0]= 54(선) - 9(선))
        if(yn) break;
        q.push(new);
q [{54,18,6},{45,15,5}]
    (순회) dd[6] {{9,3,1},{9,1,3}(선),{3,1,9},...}
        vector<int> new;
        bool yn = true;
        new.push_back(pop[0]+1);
        (순회) pop[1-3] {54(선),18,6}
            if(54(선) - 9(선) > 0) yn = false;
            new.push_back(pop[0]= 54(선) - 9(선))
        if(yn) break;
        q.push(new);
q.pop();
*/