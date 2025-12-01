#include <stdio.h>
#include <string.h>
#include <time.h>

// Function to build a filename based on goal name
void buildFileName(char *goalName, char *fileName) {
    sprintf(fileName, "goal_%s.txt", goalName);
}

// Function to build monthly report filename
void buildMonthlyReportFile(char *fileName) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(fileName, "report_%d_%02d.txt", tm.tm_year + 1900, tm.tm_mon + 1);
}

// Function to build annual report filename
void buildAnnualReportFile(char *fileName) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(fileName, "report_%d.txt", tm.tm_year + 1900);
}


int main() {
    float salary;
    float cat[11];
    float total = 0, savings = 0;

    char goalName[50];
    char fileName[100]; // goal file
    char monthlyReportFile[100];
    char annualReportFile[100];

    float goalTarget = 0, goalSaved = 0, saveThisMonth = 0;
    float finalRemaining = 0;
    FILE *fp;

    printf("\n================ EXPENSE TRACKER SYSTEM (MULTI-GOAL) ================\n");

    printf("\nEnter your total monthly salary: ");
    scanf("%f", &salary);

    printf("\n----- ENTER EXPENSES FOR EACH CATEGORY -----\n");

    const char *categoryNames[11] = {
        "",
        "Housing & Utilities",
        "Food & Groceries",
        "Transportation",
        "Bills & Subscriptions",
        "Personal & Health",
        "Household & Family",
        "Financial Commitments",
        "Entertainment & Lifestyle",
        "Education & Self-Development",
        "Miscellaneous"
    };

    for (int i = 1; i <= 10; i++) {
        printf("%d. %s: ", i, categoryNames[i]);
        scanf("%f", &cat[i]);
        total += cat[i];
    }

    savings = salary - total;

    printf("\n==================== MONTHLY REPORT ====================\n");
    printf("Total Salary             : %.2f\n", salary);
    printf("Total Expenses           : %.2f\n", total);
    printf("Remaining After Expenses : %.2f\n", savings);

    if (savings < 0) {
        printf("\nStatus: ❌ Budget Over. Cannot save for any goal.\n");
        return 0; 
    }

    printf("\nStatus: ✔ You can save this month.\n");

    // ================= GOAL SAVINGS =================
    printf("\n============= GOAL SAVINGS SYSTEM =============\n");

    printf("\nEnter your saving goal name: ");
    scanf("%s", goalName);

    buildFileName(goalName, fileName);

    printf("Enter the target amount for %s: ", goalName);
    scanf("%f", &goalTarget);

    // Load previous goal savings
    fp = fopen(fileName, "r");
    if (fp != NULL) {
        fscanf(fp, "%f", &goalSaved);
        fclose(fp);
    } else {
        goalSaved = 0;
    }

    printf("How much do you want to save for '%s' this month? ", goalName);
    scanf("%f", &saveThisMonth);

    if (saveThisMonth > savings) {
        printf("\n⚠ ERROR: Cannot save more than %.2f\n", savings);
        saveThisMonth = savings;
        printf("Saving adjusted to %.2f\n", saveThisMonth);
    }

    goalSaved += saveThisMonth;

    fp = fopen(fileName, "w");
    fprintf(fp, "%.2f", goalSaved);
    fclose(fp);

    finalRemaining = savings - saveThisMonth;

    // ======================= REPORT OUTPUT ==========================
    printf("\n=============== GOAL SAVINGS REPORT ===============\n");
    printf("Goal Name          : %s\n", goalName);
    printf("Goal Target Amount : %.2f\n", goalTarget);
    printf("Saved This Month   : %.2f\n", saveThisMonth);
    printf("Total Saved So Far : %.2f\n", goalSaved);

    if (goalSaved >= goalTarget) {
        printf("Goal Status        : 🎉 Congratulations! You reached your goal!\n");
    } else {
        printf("Goal Status        : Need %.2f more to reach target.\n",
               goalTarget - goalSaved);
    }

    printf("\nRemaining Balance AFTER Goal Savings: %.2f\n", finalRemaining);

    // ======================= BUDGET ANALYSIS ==========================
    printf("\n================ BUDGET HEALTH ANALYSIS ================\n");

    float recommended[11] = {
        0, 0.30, 0.15, 0.10, 0.10, 0.10, 0.05, 0.10, 0.05, 0.03, 0.02
    };

    for (int i = 1; i <= 10; i++) {
        float pct = cat[i] / salary;
        printf("%s: %.2f (%.1f%% of salary)", categoryNames[i], cat[i], pct * 100);

        if (pct > recommended[i]) {
            printf(" ⚠ (Over recommended!)\n");
        } else {
            printf(" ✓\n");
        }
    }

    printf("\nOverall Financial Health: ");
    if (finalRemaining > salary * 0.20)
        printf("💚 Excellent (Healthy savings!)\n");
    else if (finalRemaining > salary * 0.10)
        printf("💛 Moderate (Try reducing expenses.)\n");
    else
        printf("❤️ Critical (Reduce spending immediately!)\n");

    // ================= SAVE MONTHLY REPORT ===================
    buildMonthlyReportFile(monthlyReportFile);
    fp = fopen(monthlyReportFile, "w");

    fprintf(fp, "==== Monthly Financial Report ====\n");
    fprintf(fp, "Salary: %.2f\nExpenses: %.2f\nSavings: %.2f\n\n", salary, total, savings);

    for (int i = 1; i <= 10; i++)
        fprintf(fp, "%s: %.2f\n", categoryNames[i], cat[i]);

    fprintf(fp, "\nGoal: %s\nSaved This Month: %.2f\nTotal Saved: %.2f\nRemaining Balance: %.2f\n",
            goalName, saveThisMonth, goalSaved, finalRemaining);

    fclose(fp);

    printf("\n✔ Monthly report saved.\n");

    // =============== APPEND TO ANNUAL REPORT ===============
    buildAnnualReportFile(annualReportFile);
    fp = fopen(annualReportFile, "a");

    fprintf(fp, "Month Summary -> Salary: %.2f, Expenses: %.2f, Savings: %.2f\n",
            salary, total, savings);

    fclose(fp);

    printf("✔ Annual report updated.\n");

    printf("\n=====================================================\n");

    return 0;
}