#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addscientistwindow.h"
#include "addcomputerwindow.h"
#include "editscientistwindow.h"
#include "editcomputerwindow.h"
#include "scientistinfowindow.h"
#include "computerinfowindow.h"
#include "helpwindow.h"
#include "const.h"
#include <QLabel>

//Grænn: #5EC748
//Rauður: #E94949

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    displayAllScientists();
    displayAllComputers();
    displayAllRemovedScientists();
    displayAllRemovedComputers();
    setUpAboutTab();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayAllScientists()
{
    vector<Scientist> allScientists = _service.sciGet();
    displayScientists(allScientists);
}

void MainWindow::displayAllComputers()
{
    vector<Computer> allcomputers = _service.compGet();
    displayComputers(allcomputers);
}

void MainWindow::displayAllRemovedScientists()
{
    vector<Scientist> removedScientists = _service.getDeletedSci();
    displayRemovedScientists(removedScientists);
}

void MainWindow::displayAllRemovedComputers()
{
    vector<Computer> removedComputers = _service.getDeletedComp();
    displayRemovedComputers(removedComputers);
}

void MainWindow::displayScientists(vector<Scientist> scientists)
{
    ui->table_display_scientists->clearContents();
    ui->table_display_scientists->setRowCount(scientists.size());


    // Column 4 er falinn í öllum töflum. Það er ID til þess að sorting rugli ekki lóðréttum staðsetningum aðila í töflum.
    ui->table_display_scientists->hideColumn(4);


    for(size_t i = 0; i < scientists.size(); i++)
    {

        QString name = QString::fromStdString(scientists[i].getName());
        QString born = QString::number(scientists[i].getBirth());
        QString died;
        if(scientists[i].getDeath() == ifDead)
        {
            died = QString::fromStdString("?");
        }
        else
        {
            died = QString::number(scientists[i].getDeath());
        }
        QString gender;
        if(scientists[i].getGender() == 'm' || scientists[i].getGender() == 'M')
        {
            gender = QString::fromStdString("Male");
        }
        else
        {
            gender = QString::fromStdString("Female");
        }

        //Generate-uð ID tala sem er falin í column 4.
        QString ID = QString::number(i);

        qDebug() << name << " " << born <<" " <<  died << " " << ID;

        //Nauðsynlegt að slökkva á sorting áður en taflan fær gildi
        //annars fær hún vitlaus gildi
        ui->table_display_scientists->setSortingEnabled(false);

        ui->table_display_scientists->setItem(i, 0, new QTableWidgetItem(name));
        ui->table_display_scientists->setItem(i, 1, new QTableWidgetItem(born));
        ui->table_display_scientists->setItem(i, 2, new QTableWidgetItem(died));
        ui->table_display_scientists->setItem(i, 3, new QTableWidgetItem(gender));
        ui->table_display_scientists->setItem(i, 4, new QTableWidgetItem(ID));
        ui->table_display_scientists->setSortingEnabled(true);
    }
    _currentlyDisplaydedScientists = scientists;
}

void MainWindow::displayComputers(vector<Computer> computers)
{
    ui->table_display_computers->clearContents();
    ui->table_display_computers->setRowCount(computers.size());
    ui->table_display_computers->hideColumn(4);

    for(size_t i = 0; i < computers.size(); i++)
    {
        QString name = QString::fromStdString(computers[i].getName());
        QString type = QString::fromStdString(computers[i].getType());
        QString ifMade;
        if(computers[i].getIfMade() == 1)
        {
            ifMade = QString::fromStdString("Yes");
        }
        else
        {
            ifMade = QString::fromStdString("No");
        }
        QString yearMade;
        if(computers[i].getYearMade() == 0)
        {
            yearMade = QString::fromStdString("----");
        }
        else
        {
            yearMade = QString::number(computers[i].getYearMade());
        }

        // Falin ID tala
        QString ID = QString::number(i);
        ui->table_display_computers->setSortingEnabled(false);
        ui->table_display_computers->setItem(i, 0, new QTableWidgetItem(name));
        ui->table_display_computers->setItem(i, 1, new QTableWidgetItem(type));
        ui->table_display_computers->setItem(i, 2, new QTableWidgetItem(ifMade));
        ui->table_display_computers->setItem(i, 3, new QTableWidgetItem(yearMade));
        ui->table_display_computers->setItem(i, 4, new QTableWidgetItem(ID));
        ui->table_display_computers->setSortingEnabled(true);
    }
    _currentlyDisplaydedComputers = computers;
}

void MainWindow::on_input_search_scientists_textChanged(const QString &arg1)
{
    string searchScientistsInput = ui->input_search_scientists->text().toStdString();

    vector<Scientist> searchedScientists = _service.searchSci(searchScientistsInput);

    displayScientists(searchedScientists);

    //Villu-label-ið hreinsað
    ui->label_status_scientists->setText("");
}

void MainWindow::on_table_display_scientists_clicked(const QModelIndex &index)
{
    //Takkar með hlutverk fyrir ákveðna aðila í töflunni gerðir virktir þegar smellt er á einhvern í töflunni.
    ui->button_remove_scientists->setEnabled(true);
    ui->button_edit_scientists->setEnabled(true);
    ui->button_details_scientists->setEnabled(true);
    ui->label_status_scientists->setText("");
}

void MainWindow::on_button_remove_scientists_clicked()
{
    ui->button_recover_all_scientists->setEnabled(true);

    //Þegar eitthvað/einhver er valinn úr töflu er farið í gegnum eftirfarandi ferli til að rugla ekki aðilum saman þegar notandi notar sort.
    //Fyrst tekin röðin, næst tekin falna ID talan úr þeim dálki, svo búið til tilvik af scientist sem tekur aðila í því mengi sem eru birtir í töflunni sem er númer ID.
    int selectedScientistRow = ui->table_display_scientists->currentIndex().row();
    QString ID = ui->table_display_scientists->item(selectedScientistRow, 4)->text();
    qDebug() << "checkpoint 3";
    int scientistID = ID.toInt();

    Scientist selectedScientist = _currentlyDisplaydedScientists.at(scientistID);

    //Þó nafnið deleteSci gefi annað til kynna er engöngu að gera valid bitann 0 en ekki eyða Scientist
    bool scientistWasRemoved = _service.deleteSci(selectedScientist);
    if(scientistWasRemoved)
    {
        ui->input_search_scientists->setText("");
        displayAllScientists();
        ui->button_remove_scientists->setEnabled(false);

        //Success skilaboð eru græn en villuskilaboð rauð.
        ui->label_status_scientists->setText("<span style='color: #5EC748'>Scientist successfully removed</span>");
    }
    else
    {
        ui->label_status_scientists->setText("<span style='color: #E94949'>Scientist could not be removed</span>");
    }
    displayAllRemovedScientists();
}

void MainWindow::on_input_search_computers_textChanged(const QString &arg1)
{
    string searchComputersInput = ui->input_search_computers->text().toStdString();

    vector<Computer> searchedComputers = _service.searchComp(searchComputersInput);

    displayComputers(searchedComputers);
    ui->label_status_computers->setText("");
}

void MainWindow::on_table_display_computers_clicked(const QModelIndex &index)
{
    //Takkar með hlutverk fyrir ákveðnar tölvur í töflunni gerðir virktir þegar smellt er á einhverja tölvu í töflunni.
    ui->button_remove_computers->setEnabled(true);
    ui->button_details_computers->setEnabled(true);
    ui->button_edit_computers->setEnabled(true);
    ui->label_status_computers->setText("");
}

void MainWindow::on_button_remove_computers_clicked()
{
    ui->button_recover_all_computers->setEnabled(true);

    //Fyrst tekin röðin, næst tekin falna ID talan úr þeim dálki, svo búið til tilvik af computer sem tekur aðila í því mengi sem eru birtir í töflunni sem er númer ID.
    int selectedComputerRow = ui->table_display_computers->currentIndex().row();
    QString ID = ui->table_display_computers->item(selectedComputerRow, 4)->text();
    int computerID = ID.toInt();
    Computer selectedComputer = _currentlyDisplaydedComputers.at(computerID);

    bool computerWasRemoved = _service.deleteComp(selectedComputer);
    if(computerWasRemoved)
    {
        ui->input_search_computers->setText("");
        displayAllComputers();
        ui->button_remove_computers->setEnabled(false);
        ui->label_status_computers->setText("<span style='color: #5EC748'>Computer successfully removed</span>");
    }
    else
    {
        ui->label_status_computers->setText("<span style='color: #E94949'>Computer could not be removed</span>");
    }
    displayAllRemovedComputers();
}

void MainWindow::on_table_removed_scientists_clicked(const QModelIndex &index)
{
    ui->button_recover_scientists->setEnabled(true);
    ui->label_status_bin->setText("");
}

void MainWindow::on_table_removed_computers_clicked(const QModelIndex &index)
{
    ui->button_recover_computers->setEnabled(true);
    ui->label_status_bin->setText("");
}

void MainWindow::displayRemovedScientists(vector<Scientist> scientists)
{
    ui->table_removed_scientists->clearContents();
    ui->table_removed_scientists->setRowCount(scientists.size());

    //Geymd ID sem eru falin.
    ui->table_removed_scientists->hideColumn(4);

    if(scientists.size() > 0)
    {
        ui->button_recover_all_scientists->setEnabled(true);
    }
    for(size_t i = 0; i < scientists.size(); i++)
    {
        QString name = QString::fromStdString(scientists[i].getName());
        QString born = QString::number(scientists[i].getBirth());
        QString died;

        //ifDead er fasti í const.h sem er talan ef viðkomandi er ekki enn dáinn.
        if(scientists[i].getDeath() == ifDead)
        {
            died = QString::fromStdString("?");
        }
        else
        {
            died = QString::number(scientists[i].getDeath());
        }
        QString gender;
        if(scientists[i].getGender() == 'm' || scientists[i].getGender() == 'M')
        {
            gender = QString::fromStdString("Male");
        }
        else
        {
            gender = QString::fromStdString("Female");
        }

        //Faldar ID tölur eins og í öllum display table föllum.
        QString ID = QString::number(i);

        ui->table_removed_scientists->setSortingEnabled(false);
        ui->table_removed_scientists->setItem(i, 0, new QTableWidgetItem(name));
        ui->table_removed_scientists->setItem(i, 1, new QTableWidgetItem(born));
        ui->table_removed_scientists->setItem(i, 2, new QTableWidgetItem(died));
        ui->table_removed_scientists->setItem(i, 3, new QTableWidgetItem(gender));
        ui->table_removed_scientists->setItem(i, 4, new QTableWidgetItem(ID));
        ui->table_display_scientists->setSortingEnabled(true);
    }
    _currentlyRemovedScientists = scientists;
}

//Sama tækni notuð hér eins og í öllum display table föllum. Sjá fyrir ofan.
void MainWindow::displayRemovedComputers(vector<Computer> computers)
{
    ui->table_removed_computers->clearContents();
    ui->table_removed_computers->setRowCount(computers.size());
    ui->table_removed_computers->hideColumn(4);

    if(computers.size() > 0)
    {
        ui->button_recover_all_computers->setEnabled(true);
    }
    for(size_t i = 0; i < computers.size(); i++)
    {
        QString name = QString::fromStdString(computers[i].getName());
        QString type = QString::fromStdString(computers[i].getType());
        QString ifMade;
        if(computers[i].getIfMade() == 1)
        {
            ifMade = QString::fromStdString("Yes");
        }
        else
        {
            ifMade = QString::fromStdString("No");
        }
        QString yearMade;
        if(computers[i].getYearMade() == 0)
        {
            yearMade = QString::fromStdString("----");
        }
        else
        {
            yearMade = QString::number(computers[i].getYearMade());
        }
        QString ID = QString::number(i);

        ui->table_removed_computers->setSortingEnabled(false);
        ui->table_removed_computers->setItem(i, 0, new QTableWidgetItem(name));
        ui->table_removed_computers->setItem(i, 1, new QTableWidgetItem(type));
        ui->table_removed_computers->setItem(i, 2, new QTableWidgetItem(ifMade));
        ui->table_removed_computers->setItem(i, 3, new QTableWidgetItem(yearMade));
        ui->table_removed_computers->setItem(i, 4, new QTableWidgetItem(ID));
        ui->table_removed_computers->setSortingEnabled(true);
    }
    _currentlyRemovedComputers = computers;
}

//Sjá commentað fyrir ofan, sama tækni í þessu falli eins og flestum button föllum með virkni sem þarf staðsetningu í töflunni.
void MainWindow::on_button_recover_scientists_clicked()
{
    int selectedRecoverScientistRow = ui->table_removed_scientists->currentIndex().row();
    QString ID = ui->table_removed_scientists->item(selectedRecoverScientistRow, 4)->text();
    int scientistID = ID.toInt();
    Scientist selectedScientist = _currentlyRemovedScientists.at(scientistID);

    bool scientistWasRecovered = _service.recycleSci(selectedScientist);
    if(scientistWasRecovered)
    {
        displayAllRemovedScientists();
        ui->button_recover_scientists->setEnabled(false);
        ui->label_status_bin->setText("<span style='color: #5EC748'>Scientist successfully recovered</span>");
    }
    else
    {
        ui->label_status_bin->setText("<span style='color: #E94949'>Scientist could not be recovered</span>");
    }
    displayAllScientists();
}

//Sjá commentað fyrir ofan, sama tækni í þessu falli eins og flestum button föllum með virkni sem þarf staðsetningu í töflunni.
void MainWindow::on_button_recover_computers_clicked()
{
    int selectedRecoverComputerRow = ui->table_removed_computers->currentIndex().row();
    QString ID = ui->table_removed_computers->item(selectedRecoverComputerRow, 4)->text();
    int computerID = ID.toInt();
    Computer selectedComputer = _currentlyRemovedComputers.at(computerID);

    bool computerWasRecovered = _service.recycleComp(selectedComputer);
    if(computerWasRecovered)
    {
        displayAllRemovedComputers();
        ui->button_recover_computers->setEnabled(false);
        ui->label_status_bin->setText("<span style='color: #5EC748'>Computer successfully recovered</span>");
    }
    else
    {
        ui->label_status_bin->setText("<span style='color: #E94949'>Computer could not be recovered</span>");
    }
    displayAllComputers();
}

void MainWindow::on_button_recover_all_scientists_clicked()
{
    ui->button_recover_all_scientists->setEnabled(false);

    //bool fyrir ef náðist að recover-a alla úr bin.
    bool allWentOk = true;
    for(size_t i = 0; i < _currentlyRemovedScientists.size(); i++)
    {
        Scientist selectedScientist = _currentlyRemovedScientists[i];

        bool scientistWasRecovered = _service.recycleSci(selectedScientist);
        if(!scientistWasRecovered)
        {
            allWentOk = false;
        }
    }
    if(allWentOk)
    {
        ui->label_status_bin->setText("<span style='color: #5EC748'>All scientists successfully recovered</span>");
    }
    else
    {
        ui->label_status_bin->setText("<span style='color: #E94949'>All scientists could not be recovered</span>");
    }
    displayAllRemovedScientists();
    displayAllScientists();
}

void MainWindow::on_button_recover_all_computers_clicked()
{
    ui->button_recover_all_computers->setEnabled(false);

    //bool fyrir ef náðist að recover-a alla úr bin.
    bool allWentOk = true;
    for(size_t i = 0; i < _currentlyRemovedComputers.size(); i++)
    {
        //hér skiptir röðin ekki enis miklu máli og í föllum sem þurfa nákvæma staðsetningu í töflum, þess vegna er ekk notast við falda ID-ið.
        Computer selectedComputer = _currentlyRemovedComputers[i];

        bool computerWasRecovered = _service.recycleComp(selectedComputer);
        if(!computerWasRecovered)
        {
            allWentOk = false;
        }
    }
    if(allWentOk)
    {
        ui->label_status_bin->setText("<span style='color: #5EC748'>All computers successfully recovered</span>");
    }
    else
    {
        ui->label_status_bin->setText("<span style='color: #E94949'>All computers could not be recovered</span>");
    }
    displayAllRemovedComputers();
    displayAllComputers();
}

void MainWindow::on_button_addnew_scientists_clicked()
{
    //Keyrir nýjan glugga sem sér um add scientist.
    addScientistWindow addSci;
    addSci.exec();
    displayAllScientists();
}

void MainWindow::on_button_addnew_computers_clicked()
{
    //Keyrir nýjan glugga sem sér um add computer.
    addComputerWindow addComp;
    addComp.exec();
    displayAllComputers();
}


//í detail button fyrir scientist og computer er fyrst sóttur réttur aðili og svo hann sendur inn í nýja glugga sem birta upplýsingar um viðkomandi.
void MainWindow::on_button_details_scientists_clicked()
{
    int selectedScientistRow = ui->table_display_scientists->currentIndex().row();
    QString ID = ui->table_display_scientists->item(selectedScientistRow, 4)->text();
    int scientistID = ID.toInt();
    Scientist selectedScientist = _currentlyDisplaydedScientists.at(scientistID);

    scientistInfoWindow infoSci(selectedScientist);
    infoSci.exec();
}

void MainWindow::on_button_details_computers_clicked()
{
    int selectedComputerRow = ui->table_display_computers->currentIndex().row();
    QString ID = ui->table_display_computers->item(selectedComputerRow, 4)->text();
    int computerID = ID.toInt();
    Computer selectedComputer = _currentlyDisplaydedComputers.at(computerID);

    computerInfoWindow infoComp(selectedComputer);
    infoComp.exec();

}

// í table doubleclicked er nákvæmlega sama virkni og ef maður ýtir á details, til að auka þægindi fyrir notendur.
void MainWindow::on_table_display_scientists_doubleClicked(const QModelIndex &index)
{
    int selectedScientistRow = ui->table_display_scientists->currentIndex().row();
    QString ID = ui->table_display_scientists->item(selectedScientistRow, 4)->text();
    int scientistID = ID.toInt();
    Scientist selectedScientist = _currentlyDisplaydedScientists.at(scientistID);

    scientistInfoWindow infoSci(selectedScientist);
    infoSci.exec();
}

void MainWindow::on_table_display_computers_doubleClicked(const QModelIndex &index)
{
    int selectedComputerRow = ui->table_display_computers->currentIndex().row();
    QString ID = ui->table_display_computers->item(selectedComputerRow, 4)->text();
    int computerID = ID.toInt();
    Computer selectedComputer = _currentlyDisplaydedComputers.at(computerID);

    computerInfoWindow infoComp(selectedComputer);
    infoComp.exec();
}

//Hreinsar allan databaseinn, deletar en ekki bara stillt valid á 0. Notandinn getur byrjað strax að gera nýjan database eftir það.
void MainWindow::on_button_bin_clear_clicked()
{
    if(ui->checkbox_bin_clear->isChecked())
    {
        //Fallið er opið fyrir fleiri möguleikum en clear all. Finnst óþarfi að hafa það í forritinu.
        _service.clearData("all");
        ui->label_status_bin->setText("<span style='color: #E94949'>Database will be cleared!</span>");
    }
}

void MainWindow::on_tabs_tabBarClicked(int index)
{
    //Checkbox gert óvirkt ef farið er úr bin tabinu, til að gera öruggara fyrir að notandinn eyði ekki óvart databaseinum.
    ui->checkbox_bin_clear->setChecked(false);
    ui->button_details_computers->setEnabled(false);
    ui->button_details_scientists->setEnabled(false);
}

//Birtir readme skrá með upplýsingum fyrir notanda.
void MainWindow::on_manual_triggered()
{
    helpWindow manual;
    manual.exec();
}

//Slekkur á forritinu eftir að hafa lokað database.
void MainWindow::on_actionExit_triggered()
{
    _service.closeData();
    close();
}

void MainWindow::on_button_edit_scientists_clicked()
{
    int selectedScientistRow = ui->table_display_scientists->currentIndex().row();
    QString ID = ui->table_display_scientists->item(selectedScientistRow, 4)->text();
    int scientistID = ID.toInt();
    Scientist selectedScientist = _currentlyDisplaydedScientists.at(scientistID);

    editScientistWindow editSci(selectedScientist);
    editSci.exec();
    displayAllScientists();
}

void MainWindow::on_button_edit_computers_clicked()
{
    int selectedComputerRow = ui->table_display_computers->currentIndex().row();
    QString ID = ui->table_display_computers->item(selectedComputerRow, 4)->text();
    int computerID = ID.toInt();
    Computer selectedComputer = _currentlyDisplaydedComputers.at(computerID);

    editComputerWindow editComp(selectedComputer);
    editComp.exec();
    displayAllComputers();
}

//Just a fun bonus, and you get to .. learn things!
void MainWindow::on_button_facts_clicked()
{
    int random = rand() % 10 + 1;
    QString crazyFact;
    if(random == 1)
    {
        crazyFact = QString::fromStdString("The first electronic computer ENIAC weighed \n more than 27 tons and took up 1800 square feet!");
    }
    else if(random == 2)
    {
        crazyFact = QString::fromStdString("TYPEWRITER is the longest word that you can write using \n the letters only on one row of the keyboard of your computer!");
    }
    else if(random == 3)
    {
        crazyFact = QString::fromStdString("The first ever hard disk drive was made \n in 1979, and could hold only 5MB of data!");
    }
    else if(random == 4)
    {
        crazyFact = QString::fromStdString("Most cats have hair!");
    }
    else if(random == 5)
    {
        crazyFact = QString::fromStdString("Dolphins can not climb trees!");
    }
    else if(random == 6)
    {
        crazyFact = QString::fromStdString("Over 1 million domain names are registered every month.");
    }
    else if(random == 7)
    {
        crazyFact = QString::fromStdString("On an average work day, a typist’s fingers travel about 12.6 miles!");
    }
    else if(random == 8)
    {
        crazyFact = QString::fromStdString("'Amazing facts' backwards is 'stcaf gnizamA'!");
    }
    else if(random == 9)
    {
        crazyFact = QString::fromStdString("A dentist named Alfred Southwick invented the electric chair!");
    }
    else if(random == 10)
    {
        crazyFact = QString::fromStdString("100% of people try to plug their USB devices upside down!");
    }
    ui->label_facts->setText(crazyFact);
}

void MainWindow::setUpAboutTab()
{
    //Opnar tölvupóstinn hjá notanda og fyllir út í eyður til að senda póst á okkur, virkar ekki ef notandi er ekki með svoleiðis forrit.

    ui->label_contact_birkir->setOpenExternalLinks(true);
    QString contactBirkir = QString::fromStdString("<a href='mailto:birkir.k@me.com?subject=VLN1' style='color: #fff; text-decoration: none; padding: 20px 40px;'>Contact</a>");
    ui->label_contact_birkir->setText(contactBirkir);

    ui->label_contact_siggi->setOpenExternalLinks(true);
    QString contactSiggi = QString::fromStdString("<a href='mailto:comradesigurdur@gmail.com?subject=VLN1' style='color: #fff; text-decoration: none; padding: 20px 40px;'>Contact</a>");
    ui->label_contact_siggi->setText(contactSiggi);

    ui->label_contact_orn->setOpenExternalLinks(true);
    QString contactOrn = QString::fromStdString("<a href='mailto:orn16@ru.is?subject=VLN1' style='color: #fff; text-decoration: none; padding: 20px 40px;'>Contact</a>");
    ui->label_contact_orn->setText(contactOrn);
}
