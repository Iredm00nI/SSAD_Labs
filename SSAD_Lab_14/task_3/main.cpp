#include <iostream>
#include <string>
#include <stack>

using namespace std;

// Memento: holds editor state
class Memento {
public:
    Memento(const string& state) {
        this->state = state;
    }
    string getState() const {
        return this->state;
    }
private:
    string state;
};

// Originator: the text editor
class TextEditor {
public:
    TextEditor() = default;
    void appendText(const string& newText) {
        this->text = this->text + newText;
    }
    string getText() const {
        return this->text;
    }

    Memento save() const {
        return Memento(this->getText());
    }

    void restore(const Memento& memento) {
        this->text = memento.getState();
    }
private:
    string text;
};

// Caretaker: manages undo/redo stacks
class UndoRedoManager {
public:
    UndoRedoManager() = default;

    void saveState(TextEditor& editor) {
        undoStack.push(editor.save());
        redoStack = stack<Memento>();
    }

    void undo(TextEditor& editor) {
        if (!undoStack.empty()) {
            Memento oldState = undoStack.top();
            undoStack.pop();
            Memento newState = undoStack.top();
            redoStack.push(oldState);
            editor.restore(newState);
        }
    }

    void redo(TextEditor& editor) {
        if (!redoStack.empty()) {
            Memento oldState = redoStack.top();
            redoStack.pop();
            undoStack.push(oldState);
            editor.restore(oldState);
        }
    }
private:
    stack<Memento> undoStack;
    stack<Memento> redoStack;
};

int main() {
    TextEditor editor;
    UndoRedoManager undoRedoManager;

    // Initial text
    cout << "Initial text: " << editor.getText() << endl;

    // Append some text and save state
    editor.appendText("Hello");
    undoRedoManager.saveState(editor);
    cout << "After appending 'Hello': " << editor.getText() << endl;

    // Append more text and save state
    editor.appendText(" World");
    undoRedoManager.saveState(editor);
    cout << "After appending ' World': " << editor.getText() << endl;

    // Undo and show state
    undoRedoManager.undo(editor);
    cout << "After undoing: " << editor.getText() << endl;

    // Redo and show state
    undoRedoManager.redo(editor);
    cout << "After redoing: " << editor.getText() << endl;

    return 0;
}