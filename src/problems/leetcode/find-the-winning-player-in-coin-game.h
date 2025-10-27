class Solution {
public:
    string losingPlayer(int x, int y)
    {
        int cnt = 1;
        while(cnt)
        {
            if(x >= 1 and y-4 >= 0)
            {
                x -= 1;
                y -= 4;
                cnt++;
            }
            else
            {
                return (cnt & 1) ? "Bob" : "Alice";
            }
        }

        return " ";
    }
};
