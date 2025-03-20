#include <iostream>

using namespace std;

//......Singleton_Pattern.......

class Logger
{
private:
    static Logger* singleton;
    Logger() = default;
public:
    static Logger* getLogger() {
        if (!singleton) {
            singleton = new Logger();
        }
        return singleton;
    }

    void log(const string& message) {
        cout << "Log:" << endl << "    - " << message << endl;
    }
};

Logger* Logger::singleton = nullptr;

//......State_Pattern.......

class DocumentState
{
public:
    virtual void handleInput(const string& input) = 0;
};

class DraftState : virtual public DocumentState
{
private:
    string text;
public:
    void handleInput(const string& input) override {
        this->text = input;
        Logger::getLogger()->log("Draft has text: " + input);
    }
};

class ReviewState : virtual public DocumentState
{
private:
    string text;
public:
    void handleInput(const string& input) override {
        this->text = input;
        Logger::getLogger()->log("Review has text: " + input);
    }
};

class FinalState : virtual public DocumentState
{
private:
    string text;
public:
    void handleInput(const string& input) override {
        this->text = input;
        Logger::getLogger()->log("Final has text: " + input);
    }
};

class Document
{
private:
    DocumentState* state;
public:
    Document(DocumentState* state) {
        this->state = state;
    }

    DocumentState* getState() {
        return this->state;
    }

    void changeState(DocumentState* newState) {
        this->state = newState;
        Logger::getLogger()->log("Change document state");
    }

    void write(const string& input) {
        state->handleInput(input);
    }
};

//......Prototype_Pattern.......

class DocumentPrototype
{
protected:
    Document* document;
public:
    virtual DocumentPrototype* clone() = 0;
    void changeState(DocumentState* newState) {
        document->changeState(newState);
    }

    void write(const string& input) {
        document->write(input);
    }
};

class ReportType : virtual public DocumentPrototype
{
public:
    ReportType(Document* document) {
        this->document = document;
    }

    ReportType(ReportType& base) = delete;

    ReportType(ReportType* base) {
        this->document = new Document(base->document->getState());
        Logger::getLogger()->log("Clone report document");
    }

    DocumentPrototype* clone() override {
        return new ReportType(this);
    }
};

class InvoiceType : virtual public DocumentPrototype
{
public:
    InvoiceType(Document* document) {
        this->document = document;
    }

    InvoiceType(InvoiceType& base) = delete;

    InvoiceType(InvoiceType* base) {
        this->document = new Document(base->document->getState());
        Logger::getLogger()->log("Clone invoice document");
    }

    DocumentPrototype* clone() override {
        return new InvoiceType(this);
    }
};

int main() {
    DocumentPrototype* prototype = new ReportType(new Document(new DraftState));
    DocumentPrototype* prototype1 = prototype->clone();
    prototype->changeState(new FinalState);
    prototype1->write("new content");
    return 0;
}
