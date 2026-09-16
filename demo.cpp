#include <iostream>
#include <fstream>

int main() {
    double x = 0.0;
    double y = 0.0;
    double vx = 15.0;
    double vy = 20.0;
    double gravity = -9.8;
    double drag = 0.5;

    std::ofstream outfile("trajectory.csv");
    outfile << "step,x,y\n";

    for (int i = 0; i < 5; i++) {
        vy = vy + gravity;
        vx = vx * drag;
        vy = vy * drag;
        x = x + vx;
        y = y + vy;
        outfile << i << "," << x << "," << y << "\n";
        std::cout << "Step " << i << ": x = " << x << ", y = " << y << "\n";
    }

    outfile.close();
    return 0;
}
