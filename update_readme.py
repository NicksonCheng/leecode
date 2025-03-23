import os
import matplotlib.pyplot as plt
from pathlib import Path


def get_folder_contents(root_dir):
    """Get dictionary of folders and their files"""
    folder_contents = {}
    for folder in os.listdir(root_dir):
        if folder == "WeekContest":
            continue
        folder_path = os.path.join(root_dir, folder)
        if os.path.isdir(folder_path) and not folder.startswith("."):
            files = [
                f
                for f in os.listdir(folder_path)
                if (f.endswith(".c") or f.endswith(".cpp"))
            ]
            folder_contents[folder] = files
    return folder_contents


def generate_bar_chart(folder_contents, output_path):
    """Generate and save bar chart of question counts with dynamic colors"""

    # Create figure
    plt.figure(figsize=(10, 6))
    folders = list(folder_contents.keys())
    # Generate dynamic colors using a colormap
    folders = list(folder_contents.keys())
    counts = [len(files) for files in folder_contents.values()]
    num_folders = len(folders)
    colors = plt.cm.viridis(
        [i / float(num_folders - 1) for i in range(num_folders)]
        if num_folders > 1
        else [0]
    )

    # Create bars with dynamic colors
    bars = plt.bar(folders, counts, color=colors, width=0.3)
    # Customize chart
    plt.title("LeetCode Questions by Category")
    plt.xlabel("Categories")
    plt.ylabel("Number of Questions")
    plt.xticks(rotation=45)

    # Add value labels on top of each bar
    for bar in bars:
        height = bar.get_height()
        plt.text(
            bar.get_x() + bar.get_width() / 2.0,
            height,
            int(height),
            ha="center",
            va="bottom",
        )

    plt.tight_layout()
    plt.savefig(output_path)
    plt.close()


def update_readme(counts, folder_contents, chart_path):
    """Update README.md with folder contents and chart"""
    readme_content = "# LeetCode Problems\n\n"

    # Add folder sections with files
    for folder, files in folder_contents.items():
        readme_content += f"## {folder}\n"
        for file in files:
            if file.endswith(".c"):
                readme_content += f"- [x] {file.replace('.c', '')}\n"
            elif file.endswith(".cpp"):
                readme_content += f"- [x] {file.replace('.cpp', '')}\n"
        readme_content += "\n"

    # Add chart section
    readme_content += "## Statistical Chart\n"
    readme_content += f"current total questions: {counts}\n\n"
    readme_content += (
        f'<img src="{chart_path}" alt="questions bar chart" width="500">\n'
    )

    with open("README.md", "w") as f:
        f.write(readme_content)


def main():
    # Set paths
    root_dir = "."  # Assuming script runs in repo root
    chart_path = "chart.png"

    # Get folder contents
    folder_contents = get_folder_contents(root_dir)

    folders = list(folder_contents.keys())
    counts = 0
    for files in folder_contents.values():
        counts += len(files)
    # Generate chart
    generate_bar_chart(folder_contents, chart_path)

    # Update README
    update_readme(counts, folder_contents, chart_path)


if __name__ == "__main__":
    main()
