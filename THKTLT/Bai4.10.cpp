#include<bits/stdc++.h>
using namespace std;

int n, q;
vector< vector<string> > vector_tran;
vector< vector<string> > vector_test;
vector<int> f_max; // tan suat xuat hien tu xuat hien nhieu nhat trong van ban i
map<string, int> df; // tinh xem tu word nam trong bao nhieu van ban
map<par<string, int>, int> fe; // tinh xem tu word xuat hien bao nhieu lan trong van ban i <word, i> = int

vector<string> split_s(string str){
    vector<string> vec;

    while (!str.empty()){
        string ctt = str.substr(0, str.find(","));
        int pos = ctt.find(" ");

        if(pos > ctt.size())
            vec.push_back(ctt);
        else {
            while(pos <= ctt.size()){
                ctt.erase(pos,1);
                pos = ctt.find(" ");
            }
            vec.push_back(ctt);
        }
        if (str.find(",") > str.size()){
            break;
        } else {
            str.erase(0, str.find(",") + 1);
        }
    }

    return vec;
}

// input
void input(){
    vector<string> doc_tran;
    vector<string> doc_test;

    cin >> n;
    string str_ctt;
    getline(cin, str_ctt);

    for(int i=0; i<n; i++){
        string str_ctt;
        getline(cin, str_ctt);
        doc_tran.push_back(str_ctt);
    }

    cin >> q;
    getline(cin, str_ctt);
    for(int i=0; i<q; i++){
        string str_ctt;
        getline(cin, str_ctt);
        doc_test.push_back(str_ctt);
    }

    for(string v : doc_tran){
        vector<string> element = split_s(v);

        vector_tran.push_back(element);
    }

    for(string v : doc_test){
        vector<string> element = split_s(v);

        vector_test.push_back(element);
    }
}

// preprocessing
void pre_processing(){
    // tinh tan suat tu xuat hien nhieu nhat trong van ban i
    for(vector<string> str_ctt : vector_tran){
        map<string, int> m;

        // thiet lap tu dien mini m voi chi so : [sotu] [tansuatxuathien]
        int max_f = 0;
        for(string word_ctt : str_ctt){
            map<string, int>::iterator ite = m.find(word_ctt);
            if(ite == m.end()){ // neu tu nay chua co trong tu dien mini
                m.insert({word_ctt, 1});
            } else {
                ite->second += 1;
            }

            max_f = max(m[word_ctt], max_f);
        }
        f_max.push_back(max_f);
    }
}

int frequence_word_int_document_i(string word, int i){
    if(fe.find({word, i}) != fe.end()){ // neu da co trong kho luu tru thi lay ra va tra ve
        return fe[{word, i}];
    }

    int index = 0;
    vector<string> str_ctt = vector_tran[i];

    for(string v : str_ctt){
        if(word == v) index++;
    }

    fe.insert({{word, i}, index});
    return index;
}

int count_document_contan_word(string word){ // neu da co trong kho luu tru thi lay ket qua va tra ve
    if(df.find(word) != df.end()){
        return df[word];
    }

    int index = 0;
    for(vector<string> str_ctt : vector_tran){

        vector<string>::iterator ite = find(str_ctt.begin(), str_ctt.end(), word);
        if(ite != str_ctt.end()){
            index++;
        }
    }

    df.insert({word,index});
    return index;
}

// du doan van ban
int search_engine(vector<string> list_word){
    double score_max = -1000;
    int predict_label = -1;
    for(int i=0; i<n; i++){
        vector<string> list_word_tran_doc = vector_tran[i];

        double score = 0;
        for(string word : list_word){
            if(find(list_word_tran_doc.begin(), list_word_tran_doc.end(), word) == list_word_tran_doc.end()){ // tu nay khong xuat hien trong van ban
                continue;
            } else {
                int ftd = frequence_word_int_document_i(word, i);
                int dft = count_document_contan_word(word);
                int maxfd = f_max[i];

                double tf_word = 0.5 + 0.5 * ((double) ftd / maxfd);
                double idf_word = log2((double) n / dft);

                score += tf_word * idf_word;
            }
        }

        if(score > score_max) {
            predict_label = i;
            score_max = score;
        }
    }

    return predict_label + 1;
}

int man(){
	cout<<"Le Van Do 20194017";
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    input();
    pre_processing();

    for(int i=0; i<q; i++)
        cout << search_engine(vector_test[i]) << endl;

    return 0;
}
