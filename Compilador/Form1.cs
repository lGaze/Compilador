using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Compilador
{
    public partial class Form1 : Form
    {
        CompilerCore.Manager CompilerCore;
        bool textChanged;
        bool alreadyExist;
        SaveFileDialog saveDialog;
        OpenFileDialog openDialog;
        public Form1()
        {
            InitializeComponent();
            CompilerCore = new CompilerCore.Manager();
            textChanged = false;
            alreadyExist = false;
            saveDialog = new SaveFileDialog();
            openDialog = new OpenFileDialog();
        }

        private void textSrc_TextChanged(object sender, EventArgs e)
        {
            textChanged = true;
        }

        private void compileProgramToolStripMenuItem_Click(object sender, EventArgs e)
        {
            String[] complationDetails = CompilerCore.compileProgram(textSrc.Text);
            textOutput.Lines = complationDetails;
        }

        private void newToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (textChanged)
            {
                DialogResult result1 = MessageBox.Show("      Deseas Guardar?", "", MessageBoxButtons.YesNo);
                if (result1 == DialogResult.Yes)
                {
                    saveAsToolStripMenuItem_Click(sender, e);
                }

                else
                {
                    textSrc.Clear();
                }
            }
            else
            {
                textSrc.Clear();
            }
        }

        private void openToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (textChanged)
            {
                DialogResult result1 = MessageBox.Show("      Deseas Guardar?", "", MessageBoxButtons.YesNo);
                if (result1 == DialogResult.Yes)
                {
                    saveAsToolStripMenuItem_Click(sender, e);
                    openDialog.ShowDialog();
                    alreadyExist = true;
                }
                else
                {
                    openDialog.ShowDialog();
                    alreadyExist = true;
                }

            }
            else
            {
                openDialog.ShowDialog();
                alreadyExist = true;
            }

        }

        private void saveToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (alreadyExist)
            {
                //guarda incrementalmente
            }
            else
            {
                saveAsToolStripMenuItem_Click(sender, e);
            }

        }

        private void saveAsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            saveDialog.ShowDialog();
        }

        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
