# LeetCode Challenges with ESP32

### 🔍 **About the Project**
This repository focuses on solving popular **LeetCode challenges** using the **ESP32 microcontroller** platform. The aim is to bridge the gap between algorithmic problem-solving and embedded system development. By leveraging the ESP32's hardware and software capabilities, we not only solve coding problems but also implement practical applications in real-world embedded environments.

---

### 📂 **Repository Structure**
```plaintext
LeetCode-ESP32-Challenges/
├── README.md               # Overview of the project
├── solutions/              # Directory for problem-specific solutions
│   ├── problem_001_two_sum/
│   │   ├── main.c          # Solution for the 'Two Sum' problem
│   │   ├── problem_description.md
│   │   └── example_output.txt
│   ├── problem_002_add_two_numbers/
│   │   ├── main.c
│   │   ├── problem_description.md
│   │   └── example_output.txt
│   └── ...
├── esp32-idf-setup.md      # Guide to setting up ESP-IDF for ESP32
└── CONTRIBUTING.md         # Contribution guidelines
```

---

### 🚀 **Features**
- Solves LeetCode challenges with optimized algorithms.
- Implements, tests, and runs solutions on the ESP32 microcontroller.
- Bridges coding challenges with embedded systems for hands-on experience.
- Provides clear documentation for each problem, including:
  - Problem statement.
  - Code implementation.
  - Example outputs.

---

### 🛠️ **Getting Started**

#### **Requirements**
- **Hardware**: An ESP32 development board (e.g., ESP32-S3 or ESP32-C3).
- **Software**:
  - Visual Studio Code with the [ESP-IDF extension](https://marketplace.visualstudio.com/items?itemName=espressif.esp-idf-extension).
  - ESP-IDF framework installed.
  - Serial monitor (integrated with ESP-IDF extension in VS Code).

---

### **Instructions**

#### 1. **Set Up ESP-IDF with Visual Studio Code**
- Follow the official guide to install the [ESP-IDF extension](https://github.com/espressif/vscode-esp-idf-extension) in VS Code.
- Configure the ESP-IDF environment on your system, including Python and dependencies, following the extension's setup wizard.

#### 2. **Create a New ESP-IDF Project**
- Open **Visual Studio Code**.
- Press `Ctrl+Shift+P` and select:
  ```
  ESP-IDF: Create new project
  ```
- Choose the target as **ESP32-S3** during the setup process.

#### 3. **Copy and Paste the Solution**
- Copy the `main.c` file from the relevant problem's directory (e.g., `solutions/problem_001_two_sum/main.c`) to the `main` folder of your newly created project.

#### 4. **Build and Monitor**
- Press `Ctrl+Shift+B` to build the project.
- Flash and monitor the solution by pressing `F1`, then selecting:
  ```
  ESP-IDF: Flash (Erase) and monitor
  ```

---

### 🧑‍💻 **Contributing**
Contributions are welcome! Whether you'd like to optimize a solution, add new challenges, or improve documentation, feel free to fork the repository and submit a pull request. See `CONTRIBUTING.md` for detailed guidelines.

---

### 📄 **License**
This project is licensed under the **GNU General Public License v3.0**. See the [LICENSE](LICENSE) file for more details.

---

### 🌟 **Acknowledgments**
- [LeetCode](https://leetcode.com/) for providing amazing algorithmic challenges.
- [Espressif](https://www.espressif.com/) for the incredible ESP32 platform.
- Open-source communities for their inspiration and contributions.
