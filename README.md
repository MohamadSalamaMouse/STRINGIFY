
# Introduction
String manipulation is a concept beneath NLP's general term, which refers to the process of changing or modifying strings, in order to manipulate 
data or text and reach the required format.

##### String-manipulation can be used to perform small actions like:

<img align="right" alt="GIF" height="160px" src="https://media.giphy.com/media/du3J3cXyzhj75IOgvA/giphy.gif" /> 

 - Rearranging white spaces
 - Positioning punctuation marks
 

##### String-manipulation also involve more complicated tasks like: 
- Removing duplicated words
- Correcting spelling and grammar rules
- Finding substrings & concatenating strings
 

<h3 align="center"> What we are trying to do here is  creating a command line interface -Text Editor- which also has the ability to perform some string manipulation techniques</h3>

---

##  STRINGIFY Documentation
STRINGIFY is a String manipulation program that we developed in 8086 assembly language to perform some common text manipulation processes.

STRINGIFY program consists of main.asm file where we reference and include all other files and functions and we also have four files more which are : 
<ol dir="auto">
<li>
<p dir="auto"><strong>ui.inc ------->></strong>The main file used for rendering the program, also includes rendering related functions such as function implement delay </p>
</li>
 
<li>
<p dir="auto"><strong>caps.inc  ---->></strong>Includes functions to capitalize the beginning of the sentence and be sure that the rest of the sentence litters is lowercase  </p>
</li>

<li>
<p dir="auto"><strong>spaces.inc  -->></strong>Includes functions to remove extra white spaces  and also add white space after common punctuation marks</p>
</li>

<li>
<p dir="auto"><strong>dups.inc ---->></strong>Includes functions to remove successive duplicates words</p>
</li>


</ol>



|  Program Flow-chart             | 
| -------                         |
| <img src="https://github.com/MohamadSalamaMouse/Natural-Language-Processing/blob/main/resources/Photos/Activitydiagram1.png" width="1000" />   | 


### Implemented Features
- File handling (Data Reading and Writing to and from Files directly) 
- Make the first character in the sentence capitalized and make the rest of the letters small
- Remove extra white spaces and add spaces after punctuation marks
- Remove successive duplicate words

### Recommended future Features
- Implementing spelling Corrections  and grammar rules validation
-

#### <p align="center">Note: STRINGIFY program has an input data size limitation of 250 bytes which means that the data processed by the program can't be more than 250 character or we will face an overflow exception if size exceeds the limitation</p>
   
---

## Screenshots

 Correct capitalization rules            |  Remove & add  white spaces  
:-------------------------:|:-------------------------:
  <img src="https://github.com/MohamadSalamaMouse/Natural-Language-Processing/blob/main/resources/Photos/1.png" width="500" />  |    <img src="https://github.com/MohamadSalamaMouse/Natural-Language-Processing/blob/main/resources/Photos/2.png" width="500" />

Remove successive duplicate words            |  Execute all operations together
:-------------------------:|:-------------------------:
  <img src="https://github.com/MohamadSalamaMouse/Natural-Language-Processing/blob/main/resources/Photos/3.png" width="500" />  |    <img src="https://github.com/MohamadSalamaMouse/Natural-Language-Processing/blob/main/resources/Photos/4.png" width="500" />


## Run Locally

1- Clone the project

```bash
  git clone https://github.com/MohamadSalamaMouse/STRINGIFY
```

2- Go to the project directory

```bash
  cd STRINGIFY
```

3- Run the main.asm using any 8086 assembler. Note: [Turbo Assembler](https://sourceforge.net/projects/guitasm8086/)  is preferred cause we built project using it.

---
## Demo video
To get more information we uploaded a demo video for more explanation, which you can access by pressing [Here]()

## Feedback
IF you have any feedback, please reach out to us at mohamed.11021@stemgharbiya.moe.edu.eg


## Team Members

#### Project done under supervision of  Prof. [@Sara El-Metwally](https://github.com/SaraEl-Metwally) by:
- [@Mohamad Salama Mouse ](https://github.com/MohamadSalamaMouse) | section 8
- [@Ahmed Mohsen Awad    ](https://github.com/PrinceEGY)     | Section 1
- [@Mohamed Abo El-Seoud ](https://github.com/MAES-Pyramids) | Section 8

