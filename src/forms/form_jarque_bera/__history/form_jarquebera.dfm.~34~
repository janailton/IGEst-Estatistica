object frm_jarque_bera: Tfrm_jarque_bera
  Left = 240
  Top = 59
  BorderIcons = [biSystemMenu]
  BorderStyle = bsDialog
  Caption = 'Teste de Hip'#243'tese Jarque-Bera'
  ClientHeight = 559
  ClientWidth = 890
  Color = clBtnFace
  DefaultMonitor = dmMainForm
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  Visible = True
  OnActivate = FormActivate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 9
    Top = 8
    Width = 329
    Height = 543
    Caption = 'Entrada'
    Color = clBtnFace
    ParentBackground = False
    ParentColor = False
    TabOrder = 0
    object Label1: TLabel
      Left = 8
      Top = 19
      Width = 308
      Height = 13
      Caption = 
        'Insira o valor da amostra no campo abaixo e clique em adicionar:' +
        ' '
    end
    object Label2: TLabel
      Left = 8
      Top = 80
      Width = 78
      Height = 13
      Caption = 'Dados inseridos:'
    end
    object EditX: TEdit
      Left = 8
      Top = 48
      Width = 145
      Height = 21
      TabOrder = 0
      OnKeyDown = EditXKeyDown
    end
    object btnAdicionar: TButton
      Left = 184
      Top = 48
      Width = 113
      Height = 25
      Caption = '&Adicionar'
      TabOrder = 1
      OnClick = btnAdicionarClick
    end
    object btnExcluir: TButton
      Left = 184
      Top = 79
      Width = 113
      Height = 25
      Caption = '&Excluir'
      TabOrder = 3
      OnClick = btnExcluirClick
    end
    object btnCalcular: TButton
      Left = 184
      Top = 232
      Width = 113
      Height = 65
      Caption = '&Calcular'
      TabOrder = 2
      OnClick = btnCalcularClick
    end
    object btnExcluirTudo: TButton
      Left = 184
      Top = 112
      Width = 113
      Height = 25
      Caption = 'E&xcluir Tudo'
      TabOrder = 4
      OnClick = btnExcluirTudoClick
    end
    object ListBox1: TListBox
      Left = 8
      Top = 99
      Width = 145
      Height = 427
      ItemHeight = 13
      TabOrder = 5
    end
    object btnSalvarDados: TButton
      Left = 184
      Top = 143
      Width = 113
      Height = 25
      Caption = 'Salvar'
      TabOrder = 6
      OnClick = btnSalvarDadosClick
    end
    object btnCarregarDados: TButton
      Left = 184
      Top = 174
      Width = 113
      Height = 25
      Caption = 'Carregar Dados'
      TabOrder = 7
      OnClick = btnCarregarDadosClick
    end
  end
  object GroupBox2: TGroupBox
    Left = 344
    Top = 213
    Width = 538
    Height = 338
    Caption = 'Resultado'
    Color = clBtnFace
    ParentBackground = False
    ParentColor = False
    TabOrder = 1
    object Memo1: TMemo
      Left = 19
      Top = 22
      Width = 502
      Height = 299
      ReadOnly = True
      ScrollBars = ssVertical
      TabOrder = 0
    end
  end
  object GroupBox3: TGroupBox
    Left = 344
    Top = 8
    Width = 538
    Height = 199
    Caption = 'Teste de Hip'#243'tese'
    TabOrder = 2
    object Label3: TLabel
      Left = 19
      Top = 51
      Width = 252
      Height = 13
      Caption = 'Selecione o intervalo em que o Valor-P ser'#225' avaliado:'
    end
    object Label4: TLabel
      Left = 19
      Top = 111
      Width = 47
      Height = 13
      Caption = 'Hip'#243'teses'
    end
    object RadioButton1: TRadioButton
      Left = 312
      Top = 33
      Width = 209
      Height = 17
      Caption = '[1, 0.1]  - Com erro relativo de 1%'
      Checked = True
      TabOrder = 0
      TabStop = True
    end
    object RadioButton2: TRadioButton
      Left = 312
      Top = 56
      Width = 209
      Height = 17
      Caption = '[0.1, 0.01]  - Com erro relativo de 2%'
      TabOrder = 1
    end
    object RadioButton3: TRadioButton
      Left = 312
      Top = 79
      Width = 209
      Height = 17
      Caption = '[0.01, 0.001] - Com erro relativo de 6%'
      TabOrder = 2
    end
    object Memo2: TMemo
      Left = 19
      Top = 130
      Width = 502
      Height = 55
      Lines.Strings = (
        
          'Hip'#243'tese nula H0 - N'#227'o h'#225' diferen'#231'as entre a distribui'#231#227'o da amo' +
          'stra e  a distribui'#231#227'o normal;'
        ''
        
          'Hip'#243'tese Alternativa H1 - Existem diferen'#231'as entre a distribui'#231#227 +
          'o da amostra e  a distribui'#231#227'o normal;'
        '')
      ReadOnly = True
      TabOrder = 3
    end
  end
  object SaveDialog1: TSaveDialog
    Filter = 'Jarque-Bera Files|*.jqb'
    Left = 223
    Top = 65528
  end
  object OpenDialog1: TOpenDialog
    Left = 279
    Top = 65528
  end
end
