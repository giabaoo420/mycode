#include <iostream>
#include <string>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using namespace std;

const string CANVAS_URL = "https://rmit.instructure.com/";
const string API_TOKEN = "9595~hXLzQMyDP4Lky7axD9Qx8YGrRxQheaU4e36PmT3U9aVm4nQRBeQMMyXUDEmuDT3J";

// Callback function to write data from the HTTP response to a string
size_t WriteCallback(void* contents, size_t size, size_t nmemb, string* buffer) {
    size_t totalSize = size * nmemb;
    buffer->append((char*)contents, totalSize);
    return totalSize;
}

// Function to make GET request using libcurl
string httpGet(const string& url) {
    CURL* curl;
    CURLcode res;
    string readBuffer;

    curl = curl_easy_init();
    if (curl) {
        struct curl_slist* headers = nullptr;
        headers = curl_slist_append(headers, ("Authorization: Bearer " + API_TOKEN).c_str());

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << endl;
        }

        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);
    }
    return readBuffer;
}

// Function to get course assignments
json getCourseAssignments(const string& course_id) {
    string url = CANVAS_URL + "api/v1/courses/" + course_id + "/assignments";
    string response = httpGet(url);
    
    if (response.empty()) {
        cerr << "Failed to retrieve assignments" << endl;
        return json();
    }

    return json::parse(response);
}

// Function to print assignment details
void printAssignmentDetails(const json& assignments) {
    for (const auto& assignment : assignments) {
        cout << "Assignment: " << assignment["name"] << endl;
        cout << "Due Date: " << assignment["due_at"] << endl;
        cout << "Locked: " << (assignment["locked_for_user"] ? "Yes" : "No") << endl;
        cout << "Lock Info: " << (assignment.contains("lock_info") ? assignment["lock_info"].dump() : "N/A") << endl;
        cout << string(40, '-') << endl;
    }
}

int main() {
    // Replace with your course ID
    string course_id = "138612";

    // Get and print course assignments
    json assignments = getCourseAssignments(course_id);
    if (!assignments.is_null()) {
        printAssignmentDetails(assignments);
    }

    return 0;
}