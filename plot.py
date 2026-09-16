import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv("trajectory.csv")

plt.plot(data["x"], data["y"], marker="o")
plt.xlabel("x (horizontal distance)")
plt.ylabel("y (height)")
plt.title("Trajectory")
plt.grid(True)
plt.savefig("trajectory.png")
print("Saved plot as trajectory.png")
