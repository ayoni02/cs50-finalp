import joblib
import re, string
import nltk
nltk.download('stopwords')
from nltk.corpus import stopwords




stop_words = stopwords.words('english')

def preprocess(text):
    # Remove link,user and special characters
    text = re.sub(r"@\S+|https?:\S+|http?:\S|[^A-Za-z0-9]+", ' ', str(text).lower()).strip()

    nopunc = [char for char in text if char not in string.punctuation]
    nopunc = ''.join(nopunc)

    return [word for word in nopunc.split() if word.lower() not in stop_words]

def models(twit, path='pipeline.pkl'):
    pipeline = joblib.load(path)
    pred = pipeline.predict([twit])
    return "good" if pred[0] == 4 else "bad"

#d = input("somteging: ")

#result = models(d)

#print(result)
