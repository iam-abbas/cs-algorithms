'''
Given a list of sentence with same topics (or from a news), this function will return 
a text which have score similiar between sentences. It will be useful to find the main sentence.
'''
import numpy as np
def jaccard_similarity(str_1, str_2):
        """ compute of intersection to get similraity score between words """
        str_1 = set(str_1.split())
        str_2 = set(str_2.split())
        intersect = str_1.intersection(str_2)
        return float(len(intersect)) / (len(str_1) + len(str_2) - len(intersect))

def max_avg_jaccard_sim(sentence_list, show_avg=False):
    """ compute of intersection each sentence in cluster, and return sentence with maximum of average similarity score between sentence """
    sim = []
    text_avg_sim = {}
    for idx in range(len(sentence_list)):
        for text in sentence_list:
            if len(text) < 2:
                continue
            similarity = jaccard_similarity(sentence_list[idx], text)
            sim.append(similarity)
            text_avg_sim[sentence_list[idx]] = sum(sim) / len(sim)

    # key of max values
    if show_avg:
        return max(text_avg_sim, key=text_avg_sim.get), max(text_avg_sim.values())
    else:
        return max(text_avg_sim, key=text_avg_sim.get)


if __name__ == "__main__":
    sentences = ["Manchester United midfielder Scott McTominay secured the Man-of-the Match award after the Reds’ 3-1 win at Norwich City.",
                "The 21-year-old took home 50 per cent of your vote after netting our 21st-minute opener – which was our 2,000th strike in Premier League history.",
                "The Scotland international said he was delighted with the team's performance, as well as securing his place in the record books."]
    main_sent = max_avg_jaccard_sim(sentence_list=sentences)
    print (main_sent)