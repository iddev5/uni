import numpy as np
import matplotlib.pyplot as plt

def kmeans(X, k, max_iters=100, tol=1e-4):
    """
    Implements K-Means clustering algorithm.

    Parameters:
        X (ndarray): Input data, shape (n_samples, n_features)
        k (int): Number of clusters
        max_iters (int): Maximum number of iterations
        tol (float): Convergence tolerance for centroid movement

    Returns:
        centroids (ndarray): Final centroids
        labels (ndarray): Cluster labels for each point
    """
    # Randomly initialize centroids
    np.random.seed(42)
    random_indices = np.random.choice(len(X), k, replace=False)
    centroids = X[random_indices]

    for _ in range(max_iters):
        # Compute distances from points to centroids
        distances = np.linalg.norm(X[:, np.newaxis] - centroids, axis=2)

        # Assign each point to the nearest centroid
        labels = np.argmin(distances, axis=1)

        # Compute new centroids
        new_centroids = np.array([X[labels == i].mean(axis=0) for i in range(k)])

        # Check for convergence
        if np.all(np.abs(new_centroids - centroids) < tol):
            break

        centroids = new_centroids

    return centroids, labels


# Example usage
if __name__ == "__main__":
    # Create synthetic dataset
    from sklearn.datasets import make_blobs

    X, _ = make_blobs(n_samples=300, centers=4, cluster_std=0.6, random_state=0)

    # Run K-means
    k = 4
    centroids, labels = kmeans(X, k)

    # Plot the results
    plt.scatter(X[:, 0], X[:, 1], c=labels, cmap='viridis')
    plt.scatter(centroids[:, 0], centroids[:, 1], c='red', s=200, marker='X')
    plt.title("K-Means Clustering")
    plt.show()
