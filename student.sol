
// SPDX-License-Identifier: UNLICENSED
pragma solidity ^0.8.0;

contract StudentData {

    // Structure
    struct Student {
        string name;
        uint rollno;
    }

    // Array of structures
    Student[] public studentArr;

    // Add student
    function addStudent(string memory name, uint rollno) public {
        for (uint i = 0; i < studentArr.length; i++) {
            if (studentArr[i].rollno == rollno) {
                revert("Student with roll no already exists!");
            }
        }

        studentArr.push(Student(name, rollno));
    }

    // Display all students
    function displayAllStudents() public view returns (Student[] memory) {
        return studentArr;
    }

    // Get student by index
    function getStudentByIndex(uint index) public view returns (Student memory) {
        require(index < studentArr.length, "Index out of bound");
        return studentArr[index];
    }

    // Get total number of students
    function getLengthOfStudents() public view returns (uint) {
        return studentArr.length;
    }

    // Fallback function
    fallback() external payable {
        revert("Invalid function call!");
    }

    // Receive function
    receive() external payable {
        revert("Direct Ether transfer not allowed!");
    }
}
