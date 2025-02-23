# 🏋️‍♂️ Fitness Tracking Application in C++

## 📌 Project Overview
This project was developed as part of my **UML course at École des Mines de Saint-Étienne, ISMIN program**.  
It is a **terminal-based fitness tracking application** that allows users to:
- 🔥 Track **calories burned** based on activity type and user characteristics.
- 📏 Estimate **distance traveled** based on average speed and duration.
- 📊 View **progress history** with detailed session reports.

The application provides an **interactive menu** to manage workout sessions efficiently.

---

## 🚀 Features
✅ Multi-user management  
✅ Add workout **sessions** (activity type, duration, date)  
✅ Automatic calculation of **calories burned**  
✅ Estimation of **distance traveled** based on speed  
✅ **Progress tracking** and session history  

---

## 📊 Calculation Methods
The application uses **Metabolic Equivalent of Task (MET) values** for calorie calculation and average speeds for distance estimation.

| Activity             | MET   | Average Speed (km/h) |
|----------------------|-------|----------------------|
| Running             | 8.0   | 8 km/h               |
| Cycling            | 7.5   | 20 km/h              |
| Swimming           | 6.0   | 3 km/h               |
| Fast Walking       | 4.3   | 5.5 km/h             |
| Strength Training  | 3.5   | 0 km/h               |

The formulas used in the application:
- **Calories burned**: `MET × Weight (kg) × Duration (hours)`
- **Distance traveled**: `Speed (km/h) × Duration (hours)`

---

## 🛠️ How to Run and Test the Application Locally
Navigate to the project folder and execute the compiled file:

- make
- ./fitness_app


---

## 📌 How It Works
The user can:
1. **Create a profile**  
2. **Add a workout session** (e.g., running, cycling)  
3. **Complete a session and view progress**  
4. **Check workout history and statistics**  

---

## ✨ Future Improvements
- 💾 **Implement session saving** to a file (e.g., `data.txt`)  
- 📊 **Enhance progress tracking with statistics**  