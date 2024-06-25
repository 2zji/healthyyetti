#include <SFML/Graphics.hpp>
#include <vector>

// 윈도우 크기
const int windowWidth = 800;
const int windowHeight = 600;

// 패들 설정
const float paddleWidth = 100.f;
const float paddleHeight = 20.f;
const float paddleVelocity = 8.f;

// 공 설정
const float ballRadius = 10.f;
const float ballVelocity = 5.f;

// 벽돌 설정
const int countBlocksX = 10;
const int countBlocksY = 5;
const float blockWidth = 60.f;
const float blockHeight = 20.f;

class Paddle {
public:
    sf::RectangleShape shape;
    sf::Vector2f velocity;

    Paddle(float mX, float mY) {
        shape.setPosition(mX, mY);
        shape.setSize({ paddleWidth, paddleHeight });
        shape.setFillColor(sf::Color::Red);
        shape.setOrigin(paddleWidth / 2.f, paddleHeight / 2.f);
    }

    void update() {
        shape.move(velocity);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && left() > 0) {
            velocity.x = -paddleVelocity;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && right() < windowWidth) {
            velocity.x = paddleVelocity;
        }
        else {
            velocity.x = 0;
        }
    }

    float left() { return shape.getPosition().x - shape.getSize().x / 2.f; }
    float right() { return shape.getPosition().x + shape.getSize().x / 2.f; }
    float top() { return shape.getPosition().y - shape.getSize().y / 2.f; }
    float bottom() { return shape.getPosition().y + shape.getSize().y / 2.f; }
};

class Ball {
public:
    sf::CircleShape shape;
    sf::Vector2f velocity{ ballVelocity, ballVelocity };

    Ball(float mX, float mY) {
        shape.setPosition(mX, mY);
        shape.setRadius(ballRadius);
        shape.setFillColor(sf::Color::Yellow);
        shape.setOrigin(ballRadius, ballRadius);
    }

    void update() {
        shape.move(velocity);

        if (left() < 0) velocity.x = ballVelocity;
        else if (right() > windowWidth) velocity.x = -ballVelocity;

        if (top() < 0) velocity.y = ballVelocity;
        else if (bottom() > windowHeight) velocity.y = -ballVelocity;
    }

    float left() { return shape.getPosition().x - shape.getRadius(); }
    float right() { return shape.getPosition().x + shape.getRadius(); }
    float top() { return shape.getPosition().y - shape.getRadius(); }
    float bottom() { return shape.getPosition().y + shape.getRadius(); }
};

class Brick {
public:
    sf::RectangleShape shape;
    bool destroyed{ false };

    Brick(float mX, float mY) {
        shape.setPosition(mX, mY);
        shape.setSize({ blockWidth, blockHeight });
        shape.setFillColor(sf::Color::Green);
        shape.setOrigin(blockWidth / 2.f, blockHeight / 2.f);
    }

    float left() { return shape.getPosition().x - shape.getSize().x / 2.f; }
    float right() { return shape.getPosition().x + shape.getSize().x / 2.f; }
    float top() { return shape.getPosition().y - shape.getSize().y / 2.f; }
    float bottom() { return shape.getPosition().y + shape.getSize().y / 2.f; }
};

template <class T1, class T2>
bool isIntersecting(T1& mA, T2& mB) {
    return mA.right() >= mB.left() && mA.left() <= mB.right() && mA.bottom() >= mB.top() && mA.top() <= mB.bottom();
}

void testCollision(Paddle& mPaddle, Ball& mBall) {
    if (!isIntersecting(mPaddle, mBall)) return;

    mBall.velocity.y = -ballVelocity;

    if (mBall.shape.getPosition().x < mPaddle.shape.getPosition().x)
        mBall.velocity.x = -ballVelocity;
    else
        mBall.velocity.x = ballVelocity;
}

void testCollision(Brick& mBrick, Ball& mBall) {
    if (!isIntersecting(mBrick, mBall)) return;

    mBrick.destroyed = true;

    float overlapLeft{ mBall.right() - mBrick.left() };
    float overlapRight{ mBrick.right() - mBall.left() };
    float overlapTop{ mBall.bottom() - mBrick.top() };
    float overlapBottom{ mBrick.bottom() - mBall.top() };

    bool ballFromLeft(abs(overlapLeft) < abs(overlapRight));
    bool ballFromTop(abs(overlapTop) < abs(overlapBottom));

    float minOverlapX{ ballFromLeft ? overlapLeft : overlapRight };
    float minOverlapY{ ballFromTop ? overlapTop : overlapBottom };

    if (abs(minOverlapX) < abs(minOverlapY))
        mBall.velocity.x = ballFromLeft ? -ballVelocity : ballVelocity;
    else
        mBall.velocity.y = ballFromTop ? -ballVelocity : ballVelocity;
}

int main() {
    sf::RenderWindow window{ {windowWidth, windowHeight}, "Brick Breaker" };
    window.setFramerateLimit(60);

    Paddle paddle{ windowWidth / 2, windowHeight - 50 };
    Ball ball{ windowWidth / 2, windowHeight / 2 };

    std::vector<Brick> bricks;

    for (int iX{ 0 }; iX < countBlocksX; ++iX) {
        for (int iY{ 0 }; iY < countBlocksY; ++iY) {
            bricks.emplace_back((iX + 1) * (blockWidth + 3) + 22, (iY + 2) * (blockHeight + 3));
        }
    }

    while (true) {
        window.clear(sf::Color::Black);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) break;

        ball.update();
        paddle.update();

        testCollision(paddle, ball);

        for (auto& brick : bricks) testCollision(brick, ball);

        bricks.erase(remove_if(begin(bricks), end(bricks),
            [](const Brick& mBrick) { return mBrick.destroyed; }),
            end(bricks));

        window.draw(paddle.shape);
        window.draw(ball.shape);

        for (auto& brick : bricks) window.draw(brick.shape);

        window.display();
    }

    return 0;
}
