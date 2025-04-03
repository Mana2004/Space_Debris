import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

def read_graph_data(filename):
    nodes = {}
    edges = []
    section = None

    with open(filename, "r") as file:
        for line in file:
            line = line.strip()
            if line == "Nodes":
                section = "nodes"
                continue
            elif line == "Edges":
                section = "edges"
                continue

            if section == "nodes":
                node_id, x, y, z = map(float, line.split())
                nodes[int(node_id)] = (x, y, z)
            elif section == "edges":
                u, v = map(int, line.split())
                edges.append((u, v))

    return nodes, edges

def plot_3d_graph(nodes, edges):
    fig = plt.figure()
    ax = fig.add_subplot(111, projection='3d')

    for node_id, (x, y, z) in nodes.items():
        ax.scatter(x, y, z, color="blue", s=100)
        ax.text(x, y, z, f"{node_id}", color="red", fontsize=10)

    for u, v in edges:
        x_vals = [nodes[u][0], nodes[v][0]]
        y_vals = [nodes[u][1], nodes[v][1]]
        z_vals = [nodes[u][2], nodes[v][2]]
        ax.plot(x_vals, y_vals, z_vals, color="black")

    ax.set_xlabel("X-axis")
    ax.set_ylabel("Y-axis")
    ax.set_zlabel("Z-axis")
    ax.set_title("3D Graph Visualization")

    plt.show()

if __name__ == "__main__":
    nodes, edges = read_graph_data("graph_data.txt")
    plot_3d_graph(nodes, edges)
