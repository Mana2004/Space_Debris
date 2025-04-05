import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

def read_graph_data(filename):
    nodes = {}
    edges = []
    paths = []
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
            elif line == "Paths":
                section = "paths"
                continue

            if not line:
                continue

            if section == "nodes":
                node_id, x, y, z = map(float, line.split())
                nodes[int(node_id)] = (x, y, z)
            elif section == "edges":
                u, v = map(int, line.split())
                edges.append((u, v))
            elif section == "paths":
                u, v = map(int, line.split())
                paths.append((u, v))

    return nodes, edges, paths

def plot_3d_graph(nodes, edges, paths):
    fig = plt.figure()
    ax = fig.add_subplot(111, projection='3d')

    for node_id, (x, y, z) in nodes.items():
        ax.scatter(x, y, z, color="royalblue", s=30)
        ax.text(x, y, z, f"{node_id}", color="black", fontsize=16)

    for u, v in edges:
        x_vals = [nodes[u][0], nodes[v][0]]
        y_vals = [nodes[u][1], nodes[v][1]]
        z_vals = [nodes[u][2], nodes[v][2]]
        ax.plot(x_vals, y_vals, z_vals, color="dodgerblue", linestyle="dotted", linewidth=1.0)

    for u, v in paths:
        x_vals = [nodes[u][0], nodes[v][0]]
        y_vals = [nodes[u][1], nodes[v][1]]
        z_vals = [nodes[u][2], nodes[v][2]]
        ax.plot(x_vals, y_vals, z_vals, color="purple", linewidth=1.5)

    ax.set_xlabel("X")
    ax.set_ylabel("Y")
    ax.set_zlabel("Z")
    ax.set_title("3D Graph Visualizer")

    plt.show()

if __name__ == "__main__":
    nodes, edges, paths = read_graph_data("graph_data.txt")
    plot_3d_graph(nodes, edges, paths)
