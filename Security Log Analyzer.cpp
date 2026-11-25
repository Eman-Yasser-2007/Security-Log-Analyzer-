#include<iostream>
#include<string>
using namespace std;

class LogEntry
{
private:
    string Username;
    string Status;
    string Time;
public:
    LogEntry(string U, string S, string T)
    {
        Username = U;
        Status = S;
        Time = T;
    }
    void DisplayLog()
    {
        cout << "Username:" << Username << endl;
        cout << "Status:" << Status << endl;
        cout << "Time:" << Time << endl;
    }
    bool IsFailed()
    {
        if (Status == "FAILED")
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    string GetUsername()
    {
        return Username;
    }
};

class UserStats
{
private:
    int FailedCount;
    string Username;
public:
    UserStats(string n)
    {
        Username = n;
        FailedCount = 0;
    }
    int GetFailedCount()
    {
        return FailedCount;
    }
    void PlusFailedCount()
    {
        FailedCount++;
    }
    string GetUsername()
    {
        return Username;
    }
    UserStats()
    {
        Username = "";
        FailedCount = 0;
    }
};

int main()
{
    LogEntry arr[6] =
    {
        { "eman","FAILED","10:30" },
        { "ali","SUCCESS","10:31" },
        { "admin","FAILED","10:32" },
        { "admin","FAILED","10:33" },
        { "eman","SUCCESS","10:34" },
        { "admin","FAILED","10:35" }
    };

    int FailedCount = 0;

    cout << "===== Login Logs =====" << endl;

    for (int i = 0; i < 6; i++)
    {
        arr[i].DisplayLog();
        cout << "----------------" << endl;

        if (arr[i].IsFailed() == true)
        {
            FailedCount++;
        }
    }

    cout << "Total Failed Attempts: " << FailedCount << endl;

    UserStats Users[6];
    int UserCount = 0;

    for (int i = 0; i < 6; i++)
    {
        bool found = false;

        if (arr[i].IsFailed() == true)
        {
            for (int j = 0; j < UserCount; j++)
            {
                if (arr[i].GetUsername() == Users[j].GetUsername())
                {
                    Users[j].PlusFailedCount();
                    found = true;
                    break;
                }
            }

            if (found == false && UserCount < 6)
            {
                Users[UserCount] = UserStats(arr[i].GetUsername());
                Users[UserCount].PlusFailedCount();
                UserCount++;
            }
        }
    }

    cout << "\n===== User Statistics =====" << endl;

    for (int i = 0; i < UserCount; i++)
    {
        cout << "Username: " << Users[i].GetUsername() << endl;
        cout << "Failed Attempts: " << Users[i].GetFailedCount() << endl;

        if (Users[i].GetFailedCount() >= 3)
        {
            cout << "WARNING: Suspicious login activity detected!" << endl;
        }

        cout << "----------------" << endl;
    }

    return 0;
}

