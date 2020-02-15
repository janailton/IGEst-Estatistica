object FormMediaDPDesc: TFormMediaDPDesc
  Left = 293
  Top = 114
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsDialog
  Caption = 'Teste de Hip'#243'tese: M'#233'dia Com Desvio Padr'#227'o Desconhecido'
  ClientHeight = 376
  ClientWidth = 458
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 8
    Top = 8
    Width = 250
    Height = 185
    Caption = 'M'#233'dia com desvio padr'#227'o desconhecido'
    TabOrder = 0
    object Label1: TLabel
      Left = 16
      Top = 42
      Width = 95
      Height = 13
      Caption = 'H0                       =  '
    end
    object Label2: TLabel
      Left = 15
      Top = 64
      Width = 92
      Height = 13
      Caption = 'M'#233'dia                   ='
    end
    object Label3: TLabel
      Left = 15
      Top = 91
      Width = 90
      Height = 13
      Caption = 'Desvio padr'#227'o     ='
    end
    object Label5: TLabel
      Left = 15
      Top = 123
      Width = 89
      Height = 13
      Caption = 'N                         ='
    end
    object Label6: TLabel
      Left = 16
      Top = 150
      Width = 89
      Height = 13
      Caption = 'Confian'#231'a (%)      ='
    end
    object EditH0: TEdit
      Left = 136
      Top = 39
      Width = 97
      Height = 21
      TabOrder = 0
      Text = '0'
    end
    object EditMedia: TEdit
      Left = 136
      Top = 66
      Width = 97
      Height = 21
      TabOrder = 1
      Text = '0'
    end
    object EditDesvio: TEdit
      Left = 136
      Top = 93
      Width = 97
      Height = 21
      TabOrder = 2
      Text = '0'
    end
    object EditN: TEdit
      Left = 136
      Top = 120
      Width = 97
      Height = 21
      TabOrder = 3
      Text = '0'
    end
    object EditAlpha: TEdit
      Left = 137
      Top = 147
      Width = 97
      Height = 21
      TabOrder = 4
      Text = '0'
    end
  end
  object GroupBox2: TGroupBox
    Left = 264
    Top = 8
    Width = 185
    Height = 185
    Caption = 'Tipo de teste'
    TabOrder = 1
    object RadioButton1: TRadioButton
      Left = 31
      Top = 49
      Width = 138
      Height = 17
      Caption = 'Unilateral '#224' esquerda'
      Checked = True
      TabOrder = 0
      TabStop = True
    end
    object RadioButton2: TRadioButton
      Left = 31
      Top = 72
      Width = 114
      Height = 17
      Caption = 'Unilateral '#224' direita'
      TabOrder = 1
    end
    object RadioButton3: TRadioButton
      Left = 30
      Top = 95
      Width = 67
      Height = 17
      Caption = 'Bilateral'
      TabOrder = 2
    end
  end
  object GroupBox3: TGroupBox
    Left = 9
    Top = 199
    Width = 441
    Height = 170
    Caption = 'Sa'#237'da'
    TabOrder = 2
    object Label4: TLabel
      Left = 15
      Top = 44
      Width = 66
      Height = 13
      Caption = 'Resultado    ='
    end
    object Button1: TButton
      Left = 270
      Top = 128
      Width = 121
      Height = 25
      Caption = '&Calcular'
      TabOrder = 0
      OnClick = Button1Click
    end
    object btnAjuda: TButton
      Left = 112
      Top = 127
      Width = 121
      Height = 25
      Caption = '&Ajuda'
      TabOrder = 1
      OnClick = btnAjudaClick
    end
    object MemoResultado: TMemo
      Left = 96
      Top = 24
      Width = 329
      Height = 81
      ReadOnly = True
      TabOrder = 2
    end
  end
end
