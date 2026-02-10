import datetime

def parse_log_line(line):
    """
    Parse a log line to extract timestamp, action, and task name.
    """
    try:
        timestamp, level, action = line.split(" ", 2)
        action_parts = action.strip().split(": ")
        action_type = action_parts[0].split(" ")[0]
        task_name = action_parts[-1]
        timestamp = datetime.datetime.fromisoformat(timestamp)
        return timestamp, action_type, task_name
    except ValueError:
        print(f"Malformed line: {line}")
        return None, None, None

def process_large_log(file_path):
    """
    Process a large log file to extract start and end timestamps for tasks.
    """
    task_data = {}
    with open(file_path, "r") as file:
        for line in file:
            timestamp, action_type, task_name = parse_log_line(line)
            if not timestamp or not action_type or not task_name:
                continue

            if action_type == "Start":
                task_data[task_name] = {"start": timestamp}
            elif action_type == "End" and task_name in task_data:
                task_data[task_name]["end"] = timestamp

    # Calculate durations and display results
    for task, timestamps in task_data.items():
        start = timestamps.get("start")
        end = timestamps.get("end")
        if start and end:
            duration = end - start
            print(f"Task: {task}, Start: {start}, End: {end}, Duration: {duration}")
        else:
            print(f"Task: {task} has incomplete data.")

# Example usage
if __name__ == "__main__":
    log_file_path = "/Users/austinhong/git/my-practice/python/logs.txt"  # Replace with your log file path
    process_large_log(log_file_path)