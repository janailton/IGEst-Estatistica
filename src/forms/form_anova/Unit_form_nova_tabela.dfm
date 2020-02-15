object Form_nova_tabela: TForm_nova_tabela
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = 'Nova Tabela'
  ClientHeight = 153
  ClientWidth = 364
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 8
    Top = 8
    Width = 346
    Height = 137
    TabOrder = 0
    object Label1: TLabel
      Left = 16
      Top = 24
      Width = 156
      Height = 13
      Caption = 'N'#250'mero de repeti'#231#245'es (colunas):'
    end
    object Label2: TLabel
      Left = 16
      Top = 80
      Width = 156
      Height = 13
      Caption = 'N'#250'mero de tratamentos (linhas):'
    end
    object EditRepet: TEdit
      Left = 16
      Top = 43
      Width = 165
      Height = 21
      TabOrder = 0
    end
    object EditTrat: TEdit
      Left = 16
      Top = 99
      Width = 165
      Height = 21
      TabOrder = 1
    end
    object btnConfirmar: TButton
      Left = 232
      Top = 41
      Width = 91
      Height = 25
      Caption = 'Confirmar'
      TabOrder = 2
      OnClick = btnConfirmarClick
    end
    object btnCancelar: TButton
      Left = 232
      Top = 75
      Width = 91
      Height = 25
      Caption = 'Cancelar'
      TabOrder = 3
      OnClick = btnCancelarClick
    end
  end
end
