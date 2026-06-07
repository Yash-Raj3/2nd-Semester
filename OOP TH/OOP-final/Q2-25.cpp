#include <iostream>
#include <fstream>

using namespace std;
class Operation;
class IntelRecord;
class FileAccessException : public exception
{
public:
    const char *what() const noexcept
    {
        return "File could not be opened!";
    }
};
class ExtractionException : public exception
{
public:
    const char *what() const noexcept
    {
        return "No high-risk records found for extraction!";
    }
};
class DeleteTraceException : public exception
{
public:
    const char *what() const noexcept
    {
        return "No traces marked as deleted!";
    }
};
class cybersecurity
{
public:
    virtual void accessIntel(IntelRecord &rec) = 0;
    virtual void extractpayload(IntelRecord &rec) = 0;
    virtual void deleteTraces(IntelRecord &rec) = 0;
};

class IntelRecord
{
protected:
    int recordID;
    char targetLocation[50];
    int riskLevel;
    char payload[100];
    bool isdeleted;

public:
    friend class cybersecurity;
    friend class Operation;
    IntelRecord()
    {
        isdeleted = false;
    }
    void input()
    {
        cout << "Enter record id: ";
        cin >> recordID;
        cin.ignore();
        cout << "Enter target location: ";
        cin.getline(targetLocation, 50);
        cout << "Enter Risk Level(1-8): ";
        cin >> riskLevel;
        cin.ignore();
        cout << "Enter Payload: ";
        cin.getline(payload, 100);

        for (int i = 0; payload[i] != '\0'; i++)
        {
            payload[i] = payload[i] + 3;
        }

        isdeleted = false;
    }

    void display(bool decrypt = false)
    {
        cout << "Record Id: " << recordID << endl;
        cout << "Target Location: " << targetLocation << endl;
        cout << "Risk Level: " << riskLevel << endl;
        if (decrypt)
        {
            for (int i = 0; payload[i] != '\0'; i++)
            {
                payload[i] = payload[i] - 3;
            }
            cout << payload << endl;
        }
        else
        {
            cout << payload << endl;
        }
        cout << "Deleted: " << (isdeleted ? "Yes" : "No") << endl;
    }

    int getRiskLevel()
    {
        return riskLevel;
    }
    bool isMarkedDeleted()
    {
        return isdeleted;
    }
    void markDeleted()
    {
        isdeleted = true;
    }
};
class Operation : public cybersecurity
{
public:
    void writeTofile(IntelRecord &rec)
    {
        fstream out("file.dat", ios::binary | ios::app);
        if (!out)
        {
            throw FileAccessException();
        }
        out.write((char *)&rec, sizeof(rec));
        out.close();
    }
    void accessIntel(IntelRecord &rec)
    {
        fstream in("file.dat", ios::binary | ios::in);
        if (!in)
        {
            throw FileAccessException();
        }
        while (in.read((char *)&rec, sizeof(rec)))
        {
            if (!rec.isMarkedDeleted())
            {
                rec.display(true);
            }
        }
        in.close();
    }

    void extractpayload(IntelRecord &rec)
    {
        fstream in("file.dat", ios::binary | ios::in);
        fstream out("extracted.dat", ios::binary | ios::app);

        if (!in || !out)
        {
            throw FileAccessException();
        }

        bool found = false;
        while (in.read((char *)&rec, sizeof(rec)))
        {
            if (rec.getRiskLevel() >= 8)
            {
                out.write((char *)&rec, sizeof(rec));
                found = true;
            }
        }
        in.close();
        out.close();
        if (!found)
        {
            throw ExtractionException();
        }
    }
    void deleteTraces(IntelRecord &rec)
    {
        fstream in("file.dat", ios::binary | ios::in | ios::out);
        if (!in)
        {
            throw FileAccessException();
        }
        bool deleted = false;
        streampos pos;
        while (in.read((char *)&rec, sizeof(rec)))
        {
            if (rec.getRiskLevel() >= 8 && !rec.isMarkedDeleted())
            {
                rec.markDeleted();
                pos = in.tellg();
                in.seekp(pos - (streampos)sizeof(rec));
                in.write((char *)&rec, sizeof(rec));
                deleted = true;
            }
        }
        in.close();
        if (!deleted)
        {
            throw DeleteTraceException();
        }
    }
};
int main()
{
    Operation op;
    IntelRecord rec;

    int choice;

    do
    {
        cout << "\n===== CYBER OPERATION MENU =====\n";
        cout << "1. Add Intel Record\n";
        cout << "2. Access Intel\n";
        cout << "3. Extract High Risk Payloads\n";
        cout << "4. Delete High Risk Traces\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        try
        {
            switch (choice)
            {
            case 1:
                rec.input();
                op.writeTofile(rec);
                cout << "Record added successfully!\n";
                break;

            case 2:
                op.accessIntel(rec);
                break;

            case 3:
                op.extractpayload(rec);
                cout << "High-risk records extracted successfully!\n";
                break;

            case 4:
                op.deleteTraces(rec);
                cout << "Traces deleted successfully!\n";
                break;

            case 5:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
            }
        }
        catch (const FileAccessException &e)
        {
            cout << e.what() << endl;
        }
        catch (const ExtractionException &e)
        {
            cout << e.what() << endl;
        }
        catch (const DeleteTraceException &e)
        {
            cout << e.what() << endl;
        }
    } while (choice != 5);

    return 0;
}