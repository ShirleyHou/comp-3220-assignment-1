# Assignment 1:  (Not really) Lonely Stickman 

Features: Peppa Pig Gangsta Meme


### Project description

This project is the first stage of INFO3220 assignments.
It allows multiple characters to be desplayed on a moving background.
It also allows switching between 2 game modes (regular Peppa/Thug Life Swag Peppa) for the meme effect. 

## Design Pattern Note

Abstract Factory and Builder Pattern is used here. 

**Rationale for using the Abstract Factory pattern:**

I want to have two/more game modes (for the meme effect) to switch between. Two game modes involves different background scrolling direction and potentially different character components, but they should all have the same interface.

### abstract factory code overview
* **factory**: abstract factory interface.
* **peppafactory**: concrete factory to produce concrete products for the first game mode (horizontal background, normal characters)
* **peppa_evil_factory**: concrete factory to produce concrete second game mode. (horizontal background, gangsta characters)

* **character**: an abstract product 
* **stickman** a concrete product inherits abstract character.
* **background**: an abstract product 
* **horizontalbackground** a concrete background proudct inherits abstract background, used by peppafactory.
* **verticalbackground** a concrete background product inherits abstract background, used by peppa_evil_factory.

**Rationale for using the Builder pattern:**

The initial motivation is that I want to create multuple stickman to make the Peppa Family. A game makes out of a background, a list of characters and maybe in the future, more components (needs to be flexible). Assembling them should not be the duty of the game, but a builder instead. 

### builder design pattern overview
* **gamebuilder**: abstract builder interface.
* **peppagamebuilder**: concrete builder that uses an abstract factory interface. 

* **director**: uses information from configmanager(config file reader) and game builder, assembles its corresponding products into a concrete game, and passes the assembled game to dialog to render.

### helper classes/structs:

* **configmanager**: reads file, error handling,  and pass file information.

* **dialogue**: render the game object. controls button and user interaction.



## Getting Started

### Prerequisites

You need QT's multimedia library to run this project. 

Install QT to run. 
If simply run doesn't work, run Build->clean all, then Build->Run qmake before run.

### Understanding and Modify the config file

A sample config file should look like this:
```
{
    "Background": {
      "path": ":/resources/img/peppa_bg_1024_768.jpg",
      "velocity":20,
      "width": 1024,
      "height":768
    },
    "Character": [{
         "name": "Character_1",
         "image_path": ":/resources/img/<Character_1>.png",
         "x_pos": 500,
         "y_pos": 350,
         "x_velocity":5,
         "size":"GIANT",
         "motion":"OFF"
        },
        {"name": "Character_2",
        "image_path": ":/resources/img/<Character_2>.png",
        "x_pos": 700,
        "y_pos": 350,
        "x_velocity":5,
        "size":"GIANT",
        "motion":"FAST"

       }]
}

```
The config file should be in json format and have all the fields filled. Any file path should be added accordingly to the qt resource folder.

* **Background setting**
```
"Background": {
      "path": string, relational qt resource folder address of the background picture.
      "velocity": int, velocity of the background in the x direction,
      "width": width (x_axis length) of the background. Recommend and default to 1024.
      "height": height (y_axis length) of the background. Recommend use 768.
    },
```

* **Characters setting**

the value should be a list of Individual character setting json dictionary.

All the characters in the left, if successfully found related image path, will be rendered to the screen.


```
"Character": [
    Individual Character setting 1,
    Individual Character setting 2,
    ...
]
```

* Individual Character Setting
```
{
    "name": string, name of the individual character,

    "image_path": string, relational qt resource folder address of the background picture,

    "x_pos": int, initial distance to the left side of the window.
    "y_pos": int, initial distance to the top side of the window.

    "x_velocity": int, velocity of the background in the x direction.

    "size": string, MUST BE choosen from {"TINY", "REGULAR", "LARGE", "GIANT"}. on other case/Default to "REGULAR".

    "motion": string, MUST BE choosen from {"OFF", "ON", "FAST"}. on other case/Default to "OFF". 

}
```

**NOTICE on stickman animation**: 

To enable the "motion", the user need to make sure there are 3 or more png files stored in the qt resource `resources/img` folder for the stickman to render its animation, named in the convention `"<picture_name>.png"`,  `"<picture_name>1.png"` and `"<picture_name>2.png"`. However, only the first file name `"<picture_name>.png"` is needed in the config file. The program will search the other two. 

For example:

```
"Character": [{
         "name": "Peppa",
         "image_path": ":/resources/img/peppa.png",
         "x_pos": 500,
         "y_pos": 350,
         "x_velocity":5,
         "size":"GIANT",
         "motion":"FAST"
        }]
```
will require at least 3 files in the img folder, structured like
```
├── img
│   ├── peppa.png
│   ├── peppa1.png
│   ├── peppa2.png
```
**NOTICE on enabling stickman swag mode**: 

To make the "swag" button rendering properly, the user need to make sure there are 3 more png files stored in the qt resource `img` folder for the stickman to render its animation, named in the convention `"<picture_name>_gangsta.png"`,  `"<picture_name>_gangsta1.png"` and `"<picture_name>_gangsta2.png"`. 

For example:

```
"Character": [{
         "name": "Peppa",
         "image_path": ":/resources/img/peppa.png",
         "x_pos": 500,
         "y_pos": 350,
         "x_velocity":5,
         "size":"GIANT",
         "motion":"FAST"
        }]
```
To render the ganster mode, there will require at least 6 files in the img folder, structured like
```
├── img
│   ├── peppa.png
│   ├── peppa1.png
│   ├── peppa2.png
    ├── peppa_gangsta.png
│   ├── peppa_gangsta1.png
│   ├── peppa_gangsta2.png
```

## Authors & Music Reference

* **Shirley Hou 450538825** - [Shirley Hou](https://github.com/shirleyhou)
* music: [youtube - peppa pig theme](https://https://www.youtube.com/watch?v=DP1pQkm9Op0) , [youtube - thug life theme](https://www.youtube.com/watch?v=pvKToBa0VD8)

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

