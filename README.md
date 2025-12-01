Expense Tracker System (Multi-Goal) – C Language Project

This project is a C-based Expense Tracker System designed to help users record monthly expenses, calculate savings, monitor financial health, and manage multiple saving goals.
It also generates monthly reports and maintains an annual summary using text files.

📌 Features

✔ Tracks expenses across 10 standard categories
✔ Automatically calculates total expenses & remaining savings
✔ Performs budget health analysis based on recommended percentages
✔ Allows users to create and manage multiple saving goals
✔ Each goal has its own file storing cumulative saved amount
✔ Generates monthly financial report (with date-based file naming)
✔ Updates annual report automatically
✔ Prevents invalid savings (e.g., saving more than remaining salary)

📂 Expense Categories

Housing & Utilities

Food & Groceries

Transportation

Bills & Subscriptions

Personal & Health

Household & Family

Financial Commitments

Entertainment & Lifestyle

Education & Self-Development

Miscellaneous

🧠 Budget Health Analysis

The program compares user spending against recommended budgeting guidelines:

Housing: 30%

Food: 15%

Transport: 10%

Bills: 10%

Health: 10%

Family: 5%

Commitments: 10%

Entertainment: 5%

Education: 3%

Miscellaneous: 2%

Output shows ✔ if within limit or ⚠ if over-spent.

💾 File Handling (Core Part of Project)

The program generates multiple files automatically:

1️⃣ Goal File (goal_<name>.txt)

Stores total amount saved toward a specific goal.

2️⃣ Monthly Report (report_YYYY_MM.txt)

Includes:

Salary

Total expenses

Savings

Category-wise data

Goal status

3️⃣ Annual Report (report_YYYY.txt)

Each month appends a new summary line.

▶️ Sample Execution

User enters salary & expenses

Program calculates remaining savings

User enters a goal (e.g., Laptop)

Program updates goal file

Produces monthly report

Adds line to annual report

📌 Technologies Used

C Language

GCC Compiler

File Handling

Arrays

Strings

Time/Date Functions

🎥 Demo Video
Project demonstration video:
👉 Add your YouTube or Google Drive video link here

📘 Project Report / Blog
👉 This README contains the full project explanation.

📜 Conclusion
The Expense Tracker System successfully helps users monitor expenses, manage savings goals, and maintain year-long financial records.
It demonstrates effective use of C programming, file handling, and real-world logic in a simple yet practical application.
