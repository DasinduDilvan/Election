# C-Based Election System

A simple Command-Line Interface (CLI) election management system built in C language.  
This project replaces manual vote counting with a digital approach, ensuring fairness, security, and real-time results.

---

## Table of Contents
- [Introduction](#introduction)  
- [Features](#features)  
- [System Overview](#system-overview)  
- [Requirements](#requirements)  
- [Usage](#usage)  
- [Project Structure](#project-structure)  
- [Contributors](#contributors)  
- [License](#license)  

---

## Introduction
The C-Based Election System is designed to simplify and secure the voting process.  
It allows:
- Admins to manage candidates and approve party requests.  
- Voters to register and securely cast their votes.  
- Automatic vote tallying and result generation after the election ends.  

This project was developed as part of the Department of ICT, Faculty of Technology, University of Ruhuna.

---

## Features
### Admin
- Secure admin login.  
- Candidate and party approval.  
- Final result calculation.  

### Voter
- Register as a voter.  
- Cast vote (only once).  
- Login verification.  

### Candidate
- Register as a candidate.  
- Join/select a political party.  
- Become active after admin approval.  

### Election Process
- Real-time vote updates.  
- CLI-based results display.  
- Winner declaration after voting period.  

---

## System Overview
- Programming Language: C  
- Interface: Command-Line (CLI)  
- Database: .txt file-based storage (no SQL/No network).  
- OS Support: Windows & Ubuntu  
- Version Control: Git + GitHub  

---

## Requirements
### Functional
- Voter Registration & Login  
- Candidate Registration with Party  
- Admin Approval  
- Secure Vote Casting (one vote per voter)  
- Result Generation  

### Non-Functional
- Real-time file-based updates  
- Secure login and restricted access  
- Modular, maintainable C code  
- User-friendly CLI prompts  

---

## Usage
1. Clone the repository:
   ```bash
   git clone https://github.com/DasinduDilvan/Election.git
   cd Election
