#include <bits/stdc++.h>
#include "trie_implementation.cpp"
#include "helper_function.cpp"

using namespace std;

int main()
{
    string filename;
    Trie T;
    vector<string> data;

    // Prompt user for the file name
    cout << "Please enter the file name to load the data from (music | movies | words): ";
    cin >> filename;
    cerr << "Loading data from the file, please wait...";
    data = get_array_from_file("../Data-Source/" + filename + ".txt");
    cerr << " Data loading complete.\n";

    // Insert words into the Trie
    for (string word : data)
    {
        T.insert(word);
    }
    int choice;
    do
    {
        cout << "\n------------------------\n";
        cout << "Search Menu:\n";
        cout << "1. Search for an exact match.\n";
        cout << "2. Search by prefix.\n";
        cout << "3. Perform a universal search.\n";
        cout << "0. Exit the program.\n";
        cout << "Please select an option (0-3): ";

        cin >> choice;
        getchar();

        string pattern;

        // If the user made a valid selection (not exit)
        if (choice)
        {
            cout << "Enter the search text (or leave it empty to list all entries): ";
            getline(cin, pattern);
        }

        switch (choice)
        {
        case 1:
            // Exact search case
            if (T.search_exact(pattern))
            {
                cout << "The string '" << pattern << "' was found in the data.\n";
            }
            else
            {
                cout << "The string '" << pattern << "' was not found.\n";
            }
            break;

        case 2:
            // Prefix search case
            cout << "Results for words starting with '" << pattern << "':\n";
            for (string w : T.search_pre(pattern))
            {
                cout << w << "\n";
            }
            break;

        case 3:
            // Universal search case
            cout << "Results for universal search for pattern '" << pattern << "':\n";
            for (string w : search(data, pattern))
            {
                cout << w << "\n";
            }
            break;

        case 0:
            // Exit case
            cout << "Exiting the program. Goodbye!\n";
            break;

        default:
            cout << "Invalid choice, please select a valid option (0-3).\n";
            break;
        }

        if (choice != 0)
        {
            cout << "\nPress Enter to continue...";
            getchar();
        }

    } while (choice != 0);

    return 0;
}
