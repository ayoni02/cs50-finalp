# Tweet Sentiment Analyzer Using Flask, Scikit-Learn and Sqlite3
#### Video Demo:  https://youtu.be/ha4EHUFcsZg
#### Description:
Tweet Sentiment Analyzer
Introduction

This project utilizes a Natural Language Processing (NLP) model trained on a Kaggle dataset to analyze tweets and determine their sentiment, classifying them as either positive or negative. The web application allows users to input a copied tweet, ideally without emojis, into a provided text box. Upon clicking the "CHECK" button, the pretrained model analyzes the tweet and displays a message indicating whether it is a positive or negative sentiment tweet.
Functionality

The web application seamlessly integrates various components to achieve its functionality:
NLP Model

The core of the sentiment analysis lies in the trained NLP model, which is responsible for classifying tweets based on their sentiment. This model was meticulously trained on a comprehensive dataset from Kaggle, ensuring its accuracy and effectiveness in discerning positive and negative sentiments.
SQLite Database

To maintain a record of analyzed tweets and their corresponding sentiments, the application employs an SQLite database named "tweets.db". This database stores the tweet text and its sentiment label, providing a historical reference for users to review past analyses.
Flask Framework

The Flask framework serves as the foundation for developing the web application's backend logic. It facilitates the handling of user interactions, processing tweet inputs, and communicating with the NLP model and SQLite database.
Preprocessing Module

The "runners.py" module plays a crucial role in preprocessing the input tweet before feeding it to the NLP model. This module performs essential tasks such as removing punctuation, converting text to lowercase, and tokenizing the tweet into individual words.
HTML and CSS Styling

The HTML and CSS files act as the frontend of the web application, responsible for its user interface and visual presentation. They effectively organize the layout, display elements like the text box and sentiment labels, and enhance the overall user experience.
Installation and Usage

To install and run the web application, follow these steps:

    Prerequisites: Ensure you have Python 3.x installed, along with the necessary pip packages listed in the "requirements.txt" file.

    Database Setup: Create the SQLite database "tweets.db" using the provided SQL script.

    Model Loading: Load the pretrained NLP model from the "pipeline.pkl" file.

    Application Execution: Run the Flask application using the command "python app.py" from the project directory.

    Web Access: Open a web browser and navigate to "http://localhost:5000" to access the web application.

Enhancements and Future Directions

    Emoji Handling: Implement emoji detection and normalization to improve the model's handling of tweets containing emojis.

    Sentiment Granularity: Expand the sentiment classification beyond positive and negative to include neutral or mixed sentiments.

    Real-time Sentiment Analysis: Integrate real-time sentiment analysis capabilities to provide immediate feedback on tweets.

    Multilingual Support: Extend the application's language support to analyze tweets in multiple languages.
