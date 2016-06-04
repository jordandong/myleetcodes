/*
Design a Snake game that is played on a device with screen size = width x height. 
Play the game online if you are not familiar with the game.
The snake is initially positioned at the top left corner (0,0) with length = 1 unit.
You are given a list of food's positions in row-column order. 
When a snake eats the food, its length and the game's score both increase by 1.
Each food appears one by one on the screen.
For example, the second food will not appear until the first food was eaten by the snake.
When a food does appear on the screen, it is guaranteed that it will not appear on a block occupied by the snake.

Example:
Given width = 3, height = 2, and food = [[1,2],[0,1]].
Snake snake = new Snake(width, height, food);
Initially the snake appears at position (0,0) and the food at (1,2).

|S| | |
| | |F|
snake.move("R"); -> Returns 0

| |S| |
| | |F|
snake.move("D"); -> Returns 0

| | | |
| |S|F|
snake.move("R"); -> Returns 1 (Snake eats the first food and right after that, the second food appears at (0,1) )

| |F| |
| |S|S|
snake.move("U"); -> Returns 1

| |F|S|
| | |S|
snake.move("L"); -> Returns 2 (Snake eats the second food)

| |S|S|
| | |S|
snake.move("U"); -> Returns -1 (Game over because snake collides with border)

Credits:
Special thanks to @elmirap for adding this problem and creating all test cases.
*/

// Time:  O(s) per move, s is the current length of the snake.
// Space: O(s)
class SnakeGame {
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<pair<int, int>> food) :
               width_{width}, height_{height}, score_{0},
               food_{food.begin(), food.end()}, snake_{{0, 0}}  {
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        const auto x = snake_.back().first + direction_[direction].first;
        const auto y = snake_.back().second + direction_[direction].second;
        const auto tail = snake_.back();
        
        snake_.pop_front();
        if (!valid(x, y)) {
            return -1;
        } else if (!food_.empty() && food_.front().first == x && food_.front().second == y) {
            ++score_;
            food_.pop_front();
            snake_.push_front(tail);
        }
        snake_.push_back({x, y});
        return score_;
    }

private:
    bool valid(int x, int y) {
        if (x < 0 || x >= height_ || y < 0 || y >= width_) {
            return false;
        }
        for (const auto& p : snake_) {
            if (x == p.first && y == p.second) {
                return false;
            }
        }
        return true;
    }
    int width_, height_, score_;
    deque<pair<int, int>> food_, snake_;
    unordered_map<string, pair<int, int>> direction_ = {{"U", {-1, 0}}, {"L", {0, -1}},
                                                        {"R", {0, 1}}, {"D", {1, 0}}};
};

class SnakeGame {
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<pair<int, int>> food) {
        this->width = width;
        this->height = height;
        this->food = food;
        score = 0;
        pos.push_back({0, 0});
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        auto head = pos.front(), tail = pos.back();
        pos.pop_back();
        if (direction == "U") --head.first;
        else if (direction == "L") --head.second;
        else if (direction == "R") ++head.second;
        else if (direction == "D") ++head.first;
        if (count(pos.begin(), pos.end(), head) || head.first < 0 || head.first >= height || head.second < 0 || head.second >= width) {
            return -1;
        }
        pos.insert(pos.begin(), head);
        if (!food.empty() && head == food.front()) {
            food.erase(food.begin());
            pos.push_back(tail);
            ++score;
        }
        return score;
    }

private:
    int width, height, score;
    vector<pair<int, int>> food, pos;
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame obj = new SnakeGame(width, height, food);
 * int param_1 = obj.move(direction);
 */
