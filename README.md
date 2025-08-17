# Chat Application Test Cases - Comprehensive Testing Guide

## 📖 Overview
This document contains comprehensive test cases for the **multi-client chat application built in C**.  
The application supports **broadcasting, private messaging, file transfers, client listing, and graceful disconnection**.

---

## 🚀 Application Features
- Multi-client support (up to **5 clients**)  
- **Broadcast messaging**  
- **Private messaging**  
- **File transfer** between clients  
- **Client listing**  
- **Graceful client disconnection**  

---

## 💻 Commands Supported
- **Broadcast:** Regular text (no prefix)  
- **Private Message:** `/msg <username> <message>`  
- **File Transfer:** `/file <username> <filename>`  
- **List Clients:** `/list`  
- **Quit:** `/quit`  

---

## 📋 Test Cases

### 🔹 Basic Functionality Test Cases (1-10)

#### **Test Case 1: Server Startup and Client Connection**
**Objective:** Verify server starts correctly and accepts client connections  

**Setup:**  
- Start server: `./server`  
- Start client: `./client`  

**Input:**  
Client:  
- Server IP: `127.0.0.1`  
- Username: `GID_Alice`  

**Expected Output:**  
- **Server Output:**
  
  Server listening on port 8080...

  Maximum clients allowed: 5

  New connection accepted: username [GID_Alice]

  Client [GID_Alice]: Hello, I am GID_Alice.

  ************* Total clients: 1 *************

- **Client Output:**  

  Connected to server at 127.0.0.1:8080

  Server: Welcome GID_Alice, to my server.


---

#### **Test Case 2: Multiple Client Connections**
**Objective:** Test multiple clients connecting simultaneously  

**Setup:**  
- Server running  
- Connect 3 clients  

**Input:**  
- Client 1: `GID_Alice`  
- Client 2: `GID_Bob`  
- Client 3: `GID_Charlie`  

**Expected Output:**  
- **Server Output:**  

  New connection accepted: username [GID_Alice]

  ************* Total clients: 1 *************

  New connection accepted: username [GID_Bob]

  ************* Total clients: 2 *************

  New connection accepted: username [GID_Charlie]

  ************* Total clients: 3 *************

#### **Test Case 3: Broadcast Message**
**Objective:** Test broadcasting messages to all connected clients  

**Setup:**  
3 clients connected (Alice, Bob, Charlie)  

**Input:**  
Alice sends:  

Hello everyone, this is Alice!


**Expected Output:**  
- **Server Output:**

  /broadcast msg called from [GID_Alice], send msg [Hello everyone, this is Alice!] to all.

- **Charlie’s Client Output:**
  
  Server: client [GID_Alice]: Hello everyone, this is Alice!

- **Charlie’s Client Output:**
  
  Server: client [GID_Alice]: Hello everyone, this is Alice!

- **Alice’s Client Output:**
  
  Server: Your message sent to all clients successfully.


---

#### **Test Case 4: Private Messaging**
**Objective:** Test private messaging between specific clients  

**Setup:**  
3 clients connected (Alice, Bob, Charlie)  

**Input:**  
Alice sends:  

/msg GID_Bob Hey Bob, how are you doing?

**Expected Output:**  
- **Server Output:**  
  /msg command called from [GID_Alice], send msg [Hey Bob, how are you doing?] to [GID_Bob].

- **Bob’s Client Output:**  
  Server: client [GID_Alice]: Hey Bob, how are you doing?

- **Alice’s Client Output:**  
  Server: Your message sent to client successfully.

- **Charlie’s Client Output:**  
  (No message received)

---

#### **Test Case 5: Private Message to Non-existent User**
**Objective:** Test error handling for invalid usernames  

**Setup:**  
2 clients connected (Alice, Bob)  

**Input:**  
Alice sends:  

/msg GID_NonExistent Hello there!

**Expected Output:**  
- **Server Output:**
  /msg command called from [GID_Alice], send msg [Hello there!] to [GID_NonExistent].

- **Alice’s Client Output:**  
  Server: Sorry No Client found! with this name.


---

#### **Test Case 6: List Connected Clients**
**Objective:** Test client listing functionality  

**Setup:**  
3 clients connected (Alice, Bob, Charlie)  

**Input:**  
Alice sends:  

/list

**Expected Output:**  
- **Server Output:**  
  /list command called from [GID_Alice].

- **Alice’s Client Output:**  
  Server: List of All Clients:

  GID_Bob

  GID_Charlie


---

#### **Test Case 7: File Transfer Between Clients**
**Objective:** Test file transfer functionality  

**Setup:**  
2 clients connected (Alice, Bob)  
Create test file `test.txt` with content `"Hello from file!"`  

**Input:**  
Alice sends:  

/file GID_Bob test.txt


**Expected Output:**  
- **Server Output:**  
  /file command called from [GID_Alice], send file [test.txt] to [GID_Bob].

  File transfer ready notification sent to sender.

  File transfer completed. Total bytes: [X]

- **Alice’s Client Output:**  
  Server: FILE_READY

  File sent successfully!

- **Bob’s Client Output:**  
  Server: /file command call from client [GID_Alice] to send file [test.txt] to you.

  Receiving file: test.txt

  File received successfully!

**Post-condition:** Bob should have `test.txt` created locally.

---

#### **Test Case 8: File Transfer to Non-existent User**
**Objective:** Test file transfer error handling  

**Setup:**  
1 client connected (Alice)  

**Input:**  
/file GID_NonExistent test.txt


**Expected Output:**  
- **Server Output:**  
  /file command called from [GID_Alice], send file [test.txt] to [GID_NonExistent].

- **Alice’s Client Output:**  
  Server: Sorry! No client found with this name.


---

#### **Test Case 9: Client Disconnection (/quit)**
**Objective:** Test graceful client disconnection  

**Setup:**  
2 clients connected (Alice, Bob)  

**Input:**  
/quit


**Expected Output:**  
- **Server Output:**  
  /quit command called from [GID_Alice].

  Client [GID_Alice] disconnected.

  ************* Total clients: 1 *************

- **Alice’s Client Output:**  
  Server: Good Bye, GID_Alice.

  (Client terminates)

---

#### **Test Case 10: Maximum Client Limit**
**Objective:** Test server behavior when maximum clients exceeded  

**Setup:**  
Server configured for `MAX_CLIENTS = 5`  

**Input:**  
Connect 6th client: `GID_Overflow`  

**Expected Output:**  
- **Server Output:**  
  (Accepts connection temporarily but rejects due to limit)

- **6th Client Output:**  
  Server: Server reaches its limit, Maximum 5 clients are allowed to connect.

  (Connection closes)

---

### 🔹 Advanced Test Cases (11-20) - Critical Scenarios

#### **Test Case 11: Invalid Command Handling**
**Input:**  
/unknown command here

**Expected Output:**  
Server: Your message can't be interpreted properly.


---

#### **Test Case 12: Malformed Private Message Commands**
**Input:**  
/msg

/msg GID_Bob

/msg

**Expected Output:**  
- Server should not crash  
- Missing parameters handled gracefully  

---

#### **Test Case 13: Malformed File Transfer Commands**
**Input:**  
/file

/file GID_Bob

/file GID_Bob non_existent_file.txt

**Expected Output:**  
- For non-existent file:  
  Error opening file!

- Incomplete commands handled gracefully without crash  

---

#### **Test Case 14: File Transfer with Duplicate Filenames**
**Setup:**  
Bob already has `test.txt`  

**Input:**  
/file GID_Bob test.txt

**Expected Output:**  
- **Bob’s Client Output:**  
  Server: /file command call from client [GID_Alice] to send file [test.txt] to you.

  Receiving file: test.txt

  File received successfully!

- **Result:** File saved as `test(1).txt`

---

✅ This concludes the **comprehensive testing guide** for the multi-client chat application.  

