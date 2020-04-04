# MakeCPITBGreatAgain

Repository for creating practices/contest for **CP ITB**.

## Contributing Guide

It is recommended to follow this guide on how to contribute.

1. Project structure. This should be self-explanatory.

        ├── <problem-name>              // The Problem Name
        |   ├── tc                      // Folder test cases
        │   ├── sol.cpp                 // Main Solution
        │   ├── alt-sol.cpp             // Alternative Solutions (could be more than one)
        |   ├── spec.cpp                // Problem specification build in tcframe
        │   ├── tutorial.md             // Tutorial written in markdown
        |   ├── <problem>.tex           // Problem in LaTeX
        │   └── <problem>.pdf           // Problem in PDF
  

2. Each solution file is recommended to have the following header.

        /**
         * Author  : <Author>
         * Problem : <Problem Name>
         */

3. Each tutorial file is recommended to have the following header.


        Solution <Problem Name> oleh <Author>
