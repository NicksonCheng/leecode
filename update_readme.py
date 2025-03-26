import os
import matplotlib.pyplot as plt
from pathlib import Path
from datetime import datetime
import git
from collections import defaultdict


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
    plt.figure(figsize=(10, 6))
    folders = list(folder_contents.keys())
    counts = [len(files) for files in folder_contents.values()]
    num_folders = len(folders)
    colors = plt.cm.viridis(
        [i / float(num_folders - 1) for i in range(num_folders)]
        if num_folders > 1
        else [0]
    )

    bars = plt.bar(folders, counts, color=colors, width=0.3)
    plt.title("LeetCode Questions by Category")
    plt.xlabel("Categories")
    plt.ylabel("Number of Questions")
    plt.xticks(rotation=45)

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


def get_daily_commits(root_dir):
    """Get daily commit counts for .c and .cpp files"""
    repo = git.Repo(root_dir)
    daily_counts = defaultdict(int)

    for commit in repo.iter_commits():
        date = datetime.fromtimestamp(commit.committed_date).strftime("%m-%d")
        files = commit.stats.files
        for file_path in files.keys():
            if file_path.endswith((".c", ".cpp")):
                daily_counts[date] += 1

    return daily_counts


def generate_line_chart(daily_counts, output_path):
    """Generate and save line chart of daily question counts with Y-axis in steps of 5"""
    plt.figure(figsize=(12, 6))

    # Sort dates and get corresponding counts
    dates = sorted(daily_counts.keys())
    counts = [daily_counts[date] for date in dates]

    # Plot line chart
    plt.plot(dates, counts, "b-o", linewidth=2, markersize=8)

    # Customize chart
    plt.title("Daily LeetCode Questions")
    plt.xlabel("Date (MM-DD)")
    plt.ylabel("Number of Questions")
    plt.grid(True, linestyle="--", alpha=0.7)
    plt.xticks(rotation=45)

    # Set Y-axis to show steps of 5 (0, 5, 10, 15, ...)
    max_count = max(counts) if counts else 0
    y_ticks = range(0, max_count + 5, 5)  # Start at 0, step by 5, up to max_count + 5
    plt.yticks(y_ticks)

    # Add value labels
    for i, count in enumerate(counts):
        plt.text(i, count, str(count), ha="center", va="bottom")

    plt.tight_layout()
    plt.savefig(output_path)
    plt.close()


def update_readme(counts, folder_contents, bar_chart_path, line_chart_path):
    """Update README.md with folder contents and charts"""
    readme_content = "# LeetCode Problems\n\n"

    for folder, files in folder_contents.items():
        readme_content += f"## {folder}\n"
        for file in files:
            if file.endswith(".c"):
                readme_content += f"- [x] {file.replace('.c', '')}\n"
            elif file.endswith(".cpp"):
                readme_content += f"- [x] {file.replace('.cpp', '')}\n"
        readme_content += "\n"

    readme_content += "## Statistics\n"
    readme_content += f"Current total questions: {counts}\n\n"
    readme_content += (
        f'<img src="{bar_chart_path}" alt="questions bar chart" width="500">\n\n'
    )
    readme_content += (
        f'<img src="{line_chart_path}" alt="daily questions line chart" width="600">\n'
    )

    with open("README.md", "w") as f:
        f.write(readme_content)


def main():
    root_dir = "."
    bar_chart_path = "chart.png"
    line_chart_path = "daily_chart.png"

    folder_contents = get_folder_contents(root_dir)
    total_counts = sum(len(files) for files in folder_contents.values())

    generate_bar_chart(folder_contents, bar_chart_path)
    daily_counts = get_daily_commits(root_dir)
    generate_line_chart(daily_counts, line_chart_path)

    update_readme(total_counts, folder_contents, bar_chart_path, line_chart_path)


if __name__ == "__main__":
    main()
