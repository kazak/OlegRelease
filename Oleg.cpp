#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>

using namespace std;

//Структура для хранения данных о запросе
struct Request {
    long long time;
    string token;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    unordered_map<string, queue<Request>> users;
    for (int i = 0; i < K; ++i) {
        Request request;
        cin >> request.time >> request.token;
        queue<Request>& userRequests = users[request.token];

        //Удаляем старые запросы
        while (!userRequests.empty() && userRequests.front().time <= request.time - 1000) {
            userRequests.pop();
        }

        //Если количество запросов не превышает N, добавляем текущий запрос и печатаем его
        if (userRequests.size() < N) {
            userRequests.push(request);
            cout << request.time << " " << request.token << "\n";
        }
    }

    return 0;
}
