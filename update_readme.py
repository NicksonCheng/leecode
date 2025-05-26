import os
import matplotlib.pyplot as plt
from pathlib import Path
from datetime import datetime
import git
from collections import defaultdict

exclude_folder = ["WeekContest", "BasicC++"]


def get_status(file_path):
    """Get the status from the first line comment."""
    try:
        with open(file_path, "r") as f:
            first_line = f.readline().strip()
            if first_line == "// proficient":
                return "✅"
            elif first_line == "// hint":
                return "📝"
            elif first_line == "// solution":
                return "❌"
    except Exception:
        pass
    return "📝"  # Default to hint if no valid comment


def get_folder_contents(root_dir):
    """Get dictionary of folders and their files with status."""
    folder_contents = {}
    for folder in os.listdir(root_dir):
        if folder in exclude_folder:
            continue
        folder_path = os.path.join(root_dir, folder)
        if os.path.isdir(folder_path) and not folder.startswith("."):
            files = []
            for f in os.listdir(folder_path):
                if f.endswith(".c") or f.endswith(".cpp"):
                    file_path = os.path.join(folder_path, f)
                    status = get_status(file_path)
                    problem_name = f.replace(".cpp", "")
                    problem_name = problem_name.replace(".c", "")
                    files.append((problem_name, status))
            files.sort(key=lambda x: ["❌", "📝", "✅"].index(x[1]))

            folder_contents[folder] = files
    return folder_contents


def generate_bar_chart(folder_contents, output_path):
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


def get_daily_commits(root_dir, exclude_folder):
    repo = git.Repo(root_dir)
    daily_counts = defaultdict(int)
    daily_seen_filenames = defaultdict(set)  # Tracks filenames seen per day

    for commit in repo.iter_commits():
        date = datetime.fromtimestamp(commit.committed_date).strftime("%m-%d")
        files = commit.stats.files

        for file_path, stats in files.items():
            filename = os.path.basename(file_path)

            # Check if it's a new file (additions > 0 and deletions == 0)
            is_new_file = (
                stats.get("deletions", 0) == 0 and stats.get("insertions", 0) > 0
            )

            # Conditions: valid extension (.c or .cpp), not in excluded folders
            if (
                filename.endswith((".c", ".cpp"))
                and not any(folder in file_path for folder in exclude_folder)
                and is_new_file
            ):
                # Ensure it's a newly created file (not modified in previous commits)
                if not any(
                    file_path in parent.stats.files for parent in commit.parents
                ):
                    # Only count unique filenames per day
                    if filename not in daily_seen_filenames[date]:
                        daily_counts[date] += 1
                        daily_seen_filenames[date].add(filename)

    return daily_counts


def generate_line_chart(daily_counts, output_path):
    plt.figure(figsize=(12, 6))
    dates = sorted(daily_counts.keys())
    counts = [daily_counts[date] for date in dates]

    plt.plot(dates, counts, "b-o", linewidth=2, markersize=8)
    plt.title("Daily LeetCode Questions")
    plt.xlabel("Date (MM-DD)")
    plt.ylabel("Number of Questions")
    plt.grid(True, linestyle="--", alpha=0.7)
    plt.xticks(rotation=45)
    max_count = max(counts) if counts else 0
    y_ticks = range(0, max_count + 5, 5)
    plt.yticks(y_ticks)

    for i, count in enumerate(counts):
        plt.text(i, count, str(count), ha="center", va="bottom")

    plt.tight_layout()
    plt.savefig(output_path)
    plt.close()


def update_readme(counts, folder_contents, bar_chart_path, line_chart_path):
    readme_content = "# LeetCode Problems\n\n"
    status_counts = {
        "❌": 0,
        "📝": 0,
        "✅": 0,
    }
    status_description = {
        "❌": "can't resolve without solution",
        "📝": "can't resolve without hint",
        "✅": "resolve by self",
    }
    for folder, files in folder_contents.items():
        for problem_name, status in files:
            status_counts[status] += 1

    for status, num in status_counts.items():
        readme_content += f"{status}  {status_description[status]}: {num}\n"

    for folder, files in folder_contents.items():
        readme_content += f"## {folder}\n"
        for problem_name, status in files:
            readme_content += f"- {status} {problem_name}\n"
            status_counts[status] += 1
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
