class Solution
{
public:
    bool rotateString(string s, string goal)
    {

        if (s.length() != goal.length())
        {
            return false;
        }


        string concatenated = s + s;


        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            bool isMatch = true;
            for (int j = 0; j < n; j++)
            {
                if (concatenated[i + j] != goal[j])
                {
                    isMatch = false;
                    break;
                }
            }
            if (isMatch)
            {
                return true;
            }
        }

        return false;
    }
};
